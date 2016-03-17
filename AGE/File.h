//
//  File.h
//  AGE
//
//  Created by Mitchell Matsumori-Kelly on 2/26/16.
//  Copyright (c) 2016 Phoenix. All rights reserved.
//

#ifndef __AGE__File__
#define __AGE__File__

#include <string>
#include <vector>
#include <fstream>

namespace age {
	
	
	
	
	/** A file */
	class File {
	private:
		std::string path;
		
		
	public:
		/** Constructs a File object describing the user's home directory */
		File();
		/** Constructs a File object */
		File(const std::string &path);
		
		
		/** Returns the filepath */
		inline const std::string &GetPath() const {
			return path;
		}
		/** Checks if this file is a directory */
		bool IsDirectory() const;
		/** Checks if this file exists */
		bool Exists() const;
		
		void MakeDirectory() const;
		
		
		/** Returns the parent file */
		inline File GetParent() const {
			auto find_pos = path.rfind('/');
			if ( find_pos == std::string::npos ) return *this;
			else return path.substr(0, find_pos);
		}
		/** Returns a child file */
		inline File GetChild(const std::string &child_name) const {
			return File(path + "/" + child_name);
		}
		
		
		/** Returns the name of the file (excluding extension) */
		inline std::string GetName() const {
			std::string name_and_ext = path.substr(path.find_last_of("/") + 1);
			return name_and_ext.substr(0, name_and_ext.find_first_of("."));
		}

		
		
		
		/** Equality check */
		inline bool operator == (const File &other) const {
			return path == other.path;
		}
		/** Concatenation */
		inline File operator + (const std::string &child_name) const {
			return File(path + '/' + child_name);
		}
		/** Concatenation + Assignment */
		inline File &operator +=(const std::string &child_name) {
			path = path + '/' + child_name;
			return *this;
		}
		
		
		/** Attempts to write a string to the file */
		bool WriteText(const std::string &text, bool append = false) const;
		/** Reads text from this file */
		std::string ReadText(bool *fail_check = nullptr) const;
		/** Reads lines of text from this file */
		std::vector<std::string> ReadLines() const;
		/** Returns a list of child files */
		std::vector<File> GetChildren() const;
		
		
		/** Cast operator */
		inline operator const char*() const {
			return GetPath().c_str();
		}
	};
	
	
	
	
	class FileOutputStream {
		typedef char byte;
		
		std::fstream output_stream;
		bool open;
		
		
		template <typename T> inline void WriteArray(const T *t, long size) {
			Write(size);
			output_stream.write((char*)t, sizeof(T) * size);
		}
		
	public:
		FileOutputStream() : open(false) { }
		
		
		template <typename T> inline void Write(const T &t) {
			output_stream.write((char*)&t, sizeof(T));
		}
		
		inline bool IsOpen() const {
			return open;
		}
		bool Open(const File &file) {
			if ( open ) return false;
			output_stream.open(file.GetPath(), std::ios::binary | std::ios::out);
			return (open = output_stream.good());
		}
		void Close() {
			if ( open ) {
				output_stream.close();
				open = false;
			}
		}
		
		
		
		void WriteByte(byte x) {
			Write(x);
		}
		void WriteChar(char x) {
			Write(x);
		}
		void WriteShort(short x) {
			Write(x);
		}
		void WriteInt(int x) {
			Write(x);
		}
		void WriteLong(long x) {
			Write(x);
		}
		void WriteFloat(float x) {
			Write(x);
		}
		void WriteDouble(double x) {
			Write(x);
		}
		void WriteString(const std::string &string) {
			WriteArray(string.c_str(), string.size());
			WriteChar('\0');
		}
	};
	
	
	
	class FileInputStream {
		typedef char byte;
		
		std::ifstream input_stream;
		bool open;
		
		
		
		
		
	public:
		FileInputStream() : open(false) { }
		
		inline bool IsOpen() const {
			return open;
		}
		bool Open(const File &file) {
			if ( open ) return false;
			else {
				input_stream.open(file.GetPath(), std::ios::binary | std::ios::in);
				return (open = input_stream.good());
			}
		}
		void Close() {
			if ( open ) {
				input_stream.close();
				open = false;
			}
		}
		
		
		template <typename T> T& Read(T *t_out) {
			char read[sizeof(T)];
			input_stream.read((char*)read, sizeof(T));
			*t_out = *(T*)read;
			return *t_out;
		}
		
		
		
		byte ReadByte() {
			byte b;
			return Read<byte>(&b);
		}
		char ReadChar() {
			char c;
			return Read<byte>(&c);
		}
		short ReadShort() {
			short s;
			return Read<short>(&s);
		}
		int ReadInt() {
			int i;
			return Read<int>(&i);
		}
		long ReadLong() {
			long l;
			return Read<long>(&l);
		}
		float ReadFloat() {
			float f;
			return Read<float>(&f);
		}
		double ReadDouble() {
			double d;
			return Read<double>(&d);
		}
		std::string ReadString() {
			std::vector<char> chars;
			chars.reserve(64);
			for (int i = 0; i < sizeof(short); ++i) {
				char c = ReadChar();
				chars.push_back(c);
				if ( c == '\0' ) break; // Terminating character
			}
			
			return std::string(chars.begin(), chars.end());
		}
	};
	
	
	
	
	
	
	
}

#endif /* defined(__AGE__File__) */
