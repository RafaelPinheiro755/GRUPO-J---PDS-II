# Makefile do Projeto Final de PDS II - Grupo J
#
#   make           compila o programa (build/conecta)
#   make tests     compila e roda os testes de unidade (build/testes)
#   make coverage  roda os testes com cobertura e mostra o relatório (gcovr)
#   make docs      gera a documentação com o Doxygen (docs/html)
#   make clean     apaga tudo o que foi gerado
#
# Os .cpp de src/ entram sozinhos. O src/main.cpp vai só no programa; os
# testes usam as demais classes de src/ e os arquivos de tests/.

CXX      := g++
CXXFLAGS := -std=c++11 -Wall -Wextra -pedantic -Iinclude
LDFLAGS  :=

# O doctest passa a usar <ostream> de verdade; sem isso, o CHECK não consegue
# mostrar um shared_ptr quando o teste falha.
CXXFLAGS_TESTS := -DDOCTEST_CONFIG_USE_STD_HEADERS

BUILD := build
PROG  := $(BUILD)/conecta
TESTE := $(BUILD)/testes

SRC_LIB := $(filter-out src/main.cpp,$(wildcard src/*.cpp))
TESTS   := $(wildcard tests/*.cpp)

OBJ_LIB   := $(patsubst src/%.cpp,$(BUILD)/src/%.o,$(SRC_LIB))
OBJ_MAIN  := $(BUILD)/src/main.o
OBJ_TESTS := $(patsubst tests/%.cpp,$(BUILD)/tests/%.o,$(TESTS))

.PHONY: all tests coverage docs clean

all: $(PROG)

$(PROG): $(OBJ_LIB) $(OBJ_MAIN)
	$(CXX) $(CXXFLAGS) $^ -o $@ $(LDFLAGS)

$(TESTE): $(OBJ_LIB) $(OBJ_TESTS)
	$(CXX) $(CXXFLAGS) $^ -o $@ $(LDFLAGS)

tests: $(TESTE)
	./$(TESTE)

$(BUILD)/src/%.o: src/%.cpp
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -MMD -MP -c $< -o $@

$(BUILD)/tests/%.o: tests/%.cpp
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) $(CXXFLAGS_TESTS) -MMD -MP -c $< -o $@

coverage: clean
	$(MAKE) tests CXXFLAGS="$(CXXFLAGS) --coverage" LDFLAGS="$(LDFLAGS) --coverage"
	gcovr -r . --filter src/

docs:
	doxygen Doxyfile

clean:
	rm -rf $(BUILD)/src $(BUILD)/tests $(PROG) $(TESTE) $(PROG).exe $(TESTE).exe docs/html docs/latex

-include $(OBJ_LIB:.o=.d) $(OBJ_MAIN:.o=.d) $(OBJ_TESTS:.o=.d)
