#pragma once
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <memory>

class Symbol {
friend class SymbolTable;
public:
    Symbol(std::string id, std::vector<int>::size_type index): id_(id), index_(index) { }

private:
    std::string id_;
    std::vector<int>::size_type index_;
};

class SymbolTable {
public:
    SymbolTable() = default;

    std::vector<int>::size_type lookup(std::string s) const;
    std::vector<int>::size_type insert(std::string s);
    void dump() const;

private:
    static constexpr int nil = -1;
    std::vector<Symbol> symbolTable_;
    std::unordered_map<std::string, std::vector<int>::size_type> symbolTableIndex_;
};

std::shared_ptr<SymbolTable> create() {
    return std::make_shared<SymbolTable>();
}

inline
std::vector<int>::size_type SymbolTable::lookup(std::string s) const {
    auto find = symbolTableIndex_.find(s);
    if( find == symbolTableIndex_.end() ) return nil;
    else return find->second;
}

inline
std::vector<int>::size_type SymbolTable::insert(std::string s) {
    int s_index = lookup(s);
    if( s_index == nil ) {
        s_index = symbolTable_.size();
        symbolTable_.emplace_back( s, s_index );
        symbolTableIndex_[s] = s_index;
    }
    return s_index;
}

inline
void SymbolTable::dump() const {
    std::cout << "Symbol Table:" << std::endl;
    for(const auto& s: symbolTable_)
        std::cout << s.id_ << std::endl;
}