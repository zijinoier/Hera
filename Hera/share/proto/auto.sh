
if [ ! -d "cpp" ]; then
	mkdir cpp
fi

../../../3rdParty/protobuf/bin/protoc.exe --cpp_out=cpp *.proto