
lex_source = lex.l
output = scanner
LEX = flex

all: $(output) lex.yy.c

$(output): lex.yy.c
	g++ $< -o $@ -ll

lex.yy.c: $(lex_source) symbol_table.hh
	$(LEX) $<

.PHONY: clean
clean:
	rm lex.yy.c $(output)