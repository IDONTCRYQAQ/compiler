#pragma once
#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <memory>
#include <variant>

enum class ClassType { DATA, FUNCTION, NIL };
enum class ValueType { BOOLEAN, INTEGER, FLOAT, CHAR, STRING, VOID };
using ConstantType = std::variant<bool, int, float, char, std::string>;

struct DataType {
    ValueType value_type;
    bool is_const, is_array;
};

struct Data {
    ValueType value_type;
    ConstantType value;
};

struct FunctionType {
    std::vector<ValueType> parameters_type;
    ValueType return_type; 
};

class SymbolTable {
public:
    ClassType lookup(const std::string& id) const;
    void insert(const std::string& id, ValueType type = ValueType::INTEGER, bool is_array = false);
    template<typename T>
    void insert(const std::string& id, const T& value, ValueType type = ValueType::INTEGER, bool is_array = false);
    void insert(const std::string& id, FunctionType&& function_type);
    void dump() const;
    //  -----------------------------------------------------------    //
    void enter_block();
    void exit_block();
    //  -----------------------------------------------------------    //
    bool is_declared(const std::string& id) const;
    const ValueType get_type(const std::string& id) const;
    const DataType& get_data_type(const std::string& id) const;
    ConstantType& get_data(const std::string& id);

    void default_variable(const std::string& id, ValueType type = ValueType::INTEGER);
    
    std::string arithmetic_match(ValueType t1, ValueType t2);
	std::string match_function(const std::string& id, std::vector<ValueType> parameters_type) const;
    std::string match_procedure(const std::string& id, std::vector<ValueType> parameters_type) const;
private:
    class DataEnvironment {
    public:
        void insert(const std::string& id, ValueType type = ValueType::INTEGER, bool is_array = false);
        template<typename T>
        void insert(const std::string& id, const T& value, ValueType type = ValueType::INTEGER, bool is_array = false);
        void dump() const;

        void push_scope();
        void pop_scope();

        bool exist(const std::string& id) const;
        bool is_declared(const std::string& id) const;
        const DataType& get_data_type(const std::string& id) const;
        ConstantType& get_data(const std::string& id);
        void default_variable(const std::string& id, ValueType type = ValueType::INTEGER);
    private:
        std::vector< std::unordered_set<std::string> > scopes_;
        std::unordered_map< std::string, std::vector<DataType> > data_types_;
        std::unordered_map< std::string, std::vector<ConstantType> > data_;
        
        struct Variable { std::string ID; ValueType value_type; };
        std::vector< Variable > default_variables;
    } data_environment_;

    std::unordered_map<std::string, FunctionType> function_type_;
};

std::shared_ptr<SymbolTable> create();

template<typename T>
void SymbolTable::DataEnvironment::insert(const std::string& id, 
    const T& value, ValueType type, bool is_array) {

    auto& current_scope = scopes_.back();
    //if( current_scope.find(id) != current_scope.end() ) std::cerr << "id redeclaration"  << std::endl;
    data_types_[id].push_back( {type, true, is_array} );
    data_[id].emplace_back(value);
    current_scope.emplace(id);
}

template<typename T>
void SymbolTable::insert(const std::string& id, const T& value, ValueType type, bool is_array) {
    data_environment_.insert(id, value, type, is_array);
}