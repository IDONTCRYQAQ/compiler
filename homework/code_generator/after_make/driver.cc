#include "driver.hh"
#include "parser.hh"
#include <regex>

int driver::parse (const std::string &f)
{
  file = f;
  location.initialize (&file);
  
  fout.open(std::regex_replace(file, std::regex("scala"), "jasm"));
  fout << "/*-------------------------------------------------*/" << std::endl;
  fout << "/*                Java Assembly Code               */" << std::endl;
  fout << "/*-------------------------------------------------*/" << std::endl;

  scan_begin ();

  yy::parser parse (*this);
  parse.set_debug_level (trace_parsing);
  int res = parse ();

  scan_end ();
  
  fout.close();

  return res;
}