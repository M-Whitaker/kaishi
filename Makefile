.PHONY: openGLApplication build test clean format lint docs

openGLApplication: build
	./build/bin/examples/openGLApplication/openGLApplication

build:
	cmake -B build
	cd build && make -j8

clean:
	-rm -rf build

lint:
	@printf '\n---- CPPLINT ----\n'
	cd KaishiEngine && cpplint --recursive */*

docs:
	doxygen
