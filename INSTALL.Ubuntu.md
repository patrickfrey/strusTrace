Ubuntu 16.04 on x86_64, i686
----------------------------

# Build system
Cmake with gcc or clang. Here in this description we build with
gcc >= 4.9 (has C++11 support).

# Prerequisites
Install packages with 'apt-get'/aptitude.

## Required packages
	boost-all >= 1.57 snappy-dev leveldb-dev

# Strus prerequisite packages to install before
	strusBase strus strusAnalyzer

# Configure build and install strus prerequisite packages with GNU C/C++
	for strusprj in strusBase strus strusAnalyzer
	do
	git clone https://github.com/patrickfrey/$strusprj $strusprj
	cd $strusprj
	cmake -DCMAKE_BUILD_TYPE=Release -DLIB_INSTALL_DIR=lib .
	make
	make install
	cd ..
	done

# Configure build and install strus prerequisite packages with Clang C/C++
	for strusprj in strusBase strus strusAnalyzer
	do
	git clone https://github.com/patrickfrey/$strusprj $strusprj
	cd $strusprj
	cmake -DCMAKE_BUILD_TYPE=Release \
		-DCMAKE_C_COMPILER="clang" -DCMAKE_CXX_COMPILER="clang++" .
	make
	make install
	cd ..
	done

# Fetch sources
	git clone https://github.com/patrickfrey/strusTrace
	cd strusTrace

# Configure with GNU C/C++
	cmake -DCMAKE_BUILD_TYPE=Release .

# Configure with Clang C/C++
	cmake -DCMAKE_BUILD_TYPE=Release \
		-DCMAKE_C_COMPILER="clang" -DCMAKE_CXX_COMPILER="clang++" .

# Build
	make

# Run tests
	make test

# Install
	make install


