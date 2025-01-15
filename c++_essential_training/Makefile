# Default target is first
# This matches what VSCode does with C++ and CMake Tools
.PHONY: debug
debug:
	cmake -S . -B build/c++_essential_training/debug	\
		-DCMAKE_BUILD_TYPE=Debug						\
		-DBUILD_TESTS=OFF
	cmake --build build/c++_essential_training/debug

.PHONY: release
release:
	cmake -S . -B build/c++_essential_training/release	\
		-DCMAKE_BUILD_TYPE=Release						\
		-DBUILD_TESTS=OFF
	cmake --build build/c++_essential_training/release

.PHONY: clean
clean:
	rm -rf ./build

define help-text
Targets:
 debug            Build debug build (default)
 release          Build release build
 clean            Clean all builds
endef

.PHONY: help
help:
	@: $(info $(help-text))