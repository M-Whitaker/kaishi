.PHONY: openGLApplication build test clean

openGLApplication: build
	./build/bin/examples/openGLApplication/openGLApplication

build:
	cmake -B build
	cd build && make -j8

clean:
	-rm -rf build
