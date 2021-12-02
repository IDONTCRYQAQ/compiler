#include "symbol_table.hh"

std::shared_ptr<SymbolTable> create() {
    return std::make_shared<SymbolTable>();
}
//  <--------------------------- DataEnvironment ---------------------------



//  ---------------------------------------- insert ----------------------------------------    //
void SymbolTable::DataEnvironment::insert(
    const std::string& id, ValueType type, bool is_array) {

    auto& current_scope = scopes_.back();
    data_types_[id].push_back( {type, false, is_array} );
    current_scope.emplace(id);
}

//  ---------------------------------------- insert ----------------------------------------    //

void SymbolTable::DataEnvironment::push_scope() {
    scopes_.emplace_back( std::unordered_set<std::string>() );
    for(const auto& variable : default_variables)
        insert(variable.ID, variable.value_type);
    default_variables.clear();
}

void SymbolTable::DataEnvironment::pop_scope() {
    auto& current_scope = scopes_.back();
    for(const std::string& id: current_scope) {
        auto& id_vector = data_types_[id];
        if(id_vector.back().is_const)
            data_[id].pop_back();
        id_vector.pop_back();
        if( id_vector.empty() )
            data_types_.erase(id);
    }
    scopes_.pop_back();
}

bool SymbolTable::DataEnvironment::exist(const std::string& id) const {
    return data_types_.find(id) != data_types_.end();
}

bool SymbolTable::DataEnvironment::is_declared(const std::string& id) const {
    const auto& current_scope = scopes_.back();
    return current_scope.find(id) != current_scope.end();
}

const DataType& SymbolTable::DataEnvironment::get_data_type(
    const std::string& id) const {
    
    return data_types_.at(id).back();
}

ConstantType& SymbolTable::DataEnvironment::get_data(const std::string& id) {
    return data_.at(id).back();
}

void SymbolTable::DataEnvironment::default_variable(const std::string& id, ValueType type) {
    default_variables.push_back( {id, type} );
}

void SymbolTable::DataEnvironment::dump() const {
    for(auto data_type: data_types_)
        std::cout << data_type.first << std::endl;
}

//  --------------------------- DataEnvironment --------------------------->

ClassType SymbolTable::lookup(const std::string& id) const{
    if( function_type_.find(id) != function_type_.end() )
        return ClassType::FUNCTION;
    if( data_environment_.exist(id) ) 
        return ClassType::DATA;
    return ClassType::NIL;
}

void SymbolTable::insert(const std::string& id, ValueType type, bool is_array) {
    data_environment_.insert(id, type, is_array);
}

void SymbolTable::insert(const std::string& id, FunctionType&& function_type) {
    function_type_[id] = std::move(function_type);
}


void SymbolTable::dump() const {
    std::cout << "Symbol Table:" << std::endl;
    std::cout << "data_type:" << std::endl;
    data_environment_.dump();
    std::cout << "function_type:" << std::endl;
    for(auto function_type: function_type_)
        std::cout << function_type.first << std::endl;
}

//  ---------------------//
void SymbolTable::enter_block() {
    data_environment_.push_scope();
}
void SymbolTable::exit_block() {
    data_environment_.pop_scope();
}
//  -----------------------------------------------------------------------------------//
bool SymbolTable::is_declared(const std::string& id) const {
    return data_environment_.is_declared(id) || ( function_type_.find(id) != function_type_.end() );
}

const ValueType SymbolTable::get_type(const std::string& id) const {
    if( lookup(id) == ClassType::DATA )
        return data_environment_.get_data_type(id).value_type;
    else return function_type_.at(id).return_type;
}

const DataType& SymbolTable::get_data_type(const std::string& id) const {
    return data_environment_.get_data_type(id);
}

ConstantType& SymbolTable::get_data(const std::string& id) {
    return data_environment_.get_data(id);
}

void SymbolTable::default_variable(const std::string& id, ValueType type) {
    data_environment_.default_variable(id, type);
}

std::string SymbolTable::match_function(const std::string& id, 
					std::vector<ValueType> parameters_type) const {
    ClassType class_type = lookup(id);
    switch(class_type) {
        case ClassType::NIL : return "id: " + id + " is not declared\n";
        case ClassType::DATA : return "id: " + id + " is data, not a function\n";
        case ClassType::FUNCTION : {
            const auto& function_type = function_type_.at(id);
            if( function_type.return_type == ValueType::VOID ) 
                return "id: " + id + " is a procedure, not a function\n";
            if(function_type.parameters_type != parameters_type)
                return "id: " + id + " parameters type not matched!\n";
            return "match";
        }
    }
    return "symbol_table.cc bug";
}

std::string SymbolTable::match_procedure(const std::string& id, 
					std::vector<ValueType> parameters_type) const {
    ClassType class_type = lookup(id);
    switch(class_type) {
        case ClassType::NIL : return "id: " + id + " is not declared\n";
        case ClassType::DATA : return "id: " + id + " is data, not a function\n";
        case ClassType::FUNCTION : {
            const auto& function_type = function_type_.at(id);
            if( function_type.return_type != ValueType::VOID ) 
                return "id: " + id + " is a function, not a procedure\n";
            if(function_type.parameters_type != parameters_type)
                return "id: " + id + " parameters type not matched!\n";
            return "match";
        }
    }
    return "symbol_table.cc bug";
}

std::string SymbolTable::arithmetic_match(ValueType t1, ValueType t2) {
    auto is_arithmetic = [](ValueType t) -> bool {
        if(t == ValueType::INTEGER || t == ValueType::FLOAT) return true;
        return false;
    };
    if(is_arithmetic(t1)) {
        if(is_arithmetic(t2)) {
            if(t1 == t2) return "match";
            else return "type not matched\n";
        } else return "right operand is not arithmetic expression\n";
    } else {
        if(is_arithmetic(t2))
            return "left operand is not arithmetic expression\n";
        else return "operands are not arithmetic expression\n";
    }
}