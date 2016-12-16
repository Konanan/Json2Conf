/**
mode有下列几种形态字符串:
"r" 以只读方式打开文件，该文件必须存在。
"r+" 以可读写方式打开文件，该文件必须存在。
"rb+" 读写打开一个二进制文件，允许读写数据，文件必须存在。
"w" 打开只写文件，若文件存在则文件长度清为0，即该文件内容会消失。若文件不存在则建立该文件。
"w+" 打开可读写文件，若文件存在则文件长度清为零，即该文件内容会消失。若文件不存在则建立该文件。
"a" 以附加的方式打开只写文件。若文件不存在，则会建立该文件，如果文件存在，写入的数据会被加到文件尾，即文件原先的内容会被保留。（EOF符保留）
"a+" 以附加方式打开可读写的文件。若文件不存在，则会建立该文件，如果文件存在，写入的数据会被加到文件尾后，即文件原先的内容会被保留。 （原来的EOF符不保留）
"wb" 只写打开或新建一个二进制文件；只允许写数据。
"wb+" 读写打开或建立一个二进制文件，允许读和写
"wx" 创建文本文件,只允许写入数据.[C11]
"wbx" 创建一个二进制文件,只允许写入数据.[C11]
"w+x" 创建一个文本文件,允许读写.[C11]
"wb+x" 创建一个二进制文件,允许读写.[C11]
"w+bx" 和"wb+x"相同[C11]
"rt" 只读打开一个文本文件，只允许读数据
"wt" 只写打开或建立一个文本文件，只允许写数据
"at" 追加打开一个文本文件，并在文件末尾写数据
"rb" 只读打开一个二进制文件，只允许读数据
"wb" 只写打开或建立一个二进制文件，只允许写数据
"ab" 追加打开一个二进制文件，并在文件末尾写数据
"rt+" 读写打开一个文本文件，允许读和写
"wt+" 读写打开或建立一个文本文件，允许读写
"at+" 读写打开一个文本文件，允许读，或在文件末追加数据
"rb+" 读写打开一个二进制文件，允许读和写
"ab+" 读写打开一个二进制文件，允许读，或在文件末追加数据
以x结尾的模式为独占模式,文件已存在或者无法创建(一般是路径不正确)都会导致fopen失败.文件以操作系统支持的独占模式打开.[C11]

for example: 

	unsigned long size = 0;
	unsigned char* data = File::getFileData("D:\\tools\\android-ndk-r10d-windows.zip","rb",&size);

	printf("file size is %ld \n", size);

	if(File::writeData(data,"C:\\Users\\Konan\\Desktop\\xxx\\mmm.txt","wb",size))
	{
		printf("write file size success \n");
	}

**/

#ifndef __CC_FILEUTILS_H__
#define __CC_FILEUTILS_H__

class File
{
public:
    /**
     *  Gets resource file data
     *
     *  @param[in]  pszFileName The resource file name which contains the path.
     *  @param[in]  pszMode The read mode of the file.
     *  @param[out] pSize If the file read operation succeeds, it will be the data size, otherwise 0.
     *  @return Upon success, a pointer to the data is returned, otherwise NULL.
     *  @warning Recall: you are responsible for calling delete[] on any Non-NULL pointer returned.
     *  @js NA
     */
    static unsigned char* getFileData(const char* pszFileName, const char* pszMode, unsigned long * pSize);
	static bool writeData(unsigned char* data,const char *path, const char* pszMode, unsigned long pSize);
};

#endif