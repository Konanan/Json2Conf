/**
mode�����м�����̬�ַ���:
"r" ��ֻ����ʽ���ļ������ļ�������ڡ�
"r+" �Կɶ�д��ʽ���ļ������ļ�������ڡ�
"rb+" ��д��һ���������ļ��������д���ݣ��ļ�������ڡ�
"w" ��ֻд�ļ������ļ��������ļ�������Ϊ0�������ļ����ݻ���ʧ�����ļ��������������ļ���
"w+" �򿪿ɶ�д�ļ������ļ��������ļ�������Ϊ�㣬�����ļ����ݻ���ʧ�����ļ��������������ļ���
"a" �Ը��ӵķ�ʽ��ֻд�ļ������ļ������ڣ���Ὠ�����ļ�������ļ����ڣ�д������ݻᱻ�ӵ��ļ�β�����ļ�ԭ�ȵ����ݻᱻ��������EOF��������
"a+" �Ը��ӷ�ʽ�򿪿ɶ�д���ļ������ļ������ڣ���Ὠ�����ļ�������ļ����ڣ�д������ݻᱻ�ӵ��ļ�β�󣬼��ļ�ԭ�ȵ����ݻᱻ������ ��ԭ����EOF����������
"wb" ֻд�򿪻��½�һ���������ļ���ֻ����д���ݡ�
"wb+" ��д�򿪻���һ���������ļ����������д
"wx" �����ı��ļ�,ֻ����д������.[C11]
"wbx" ����һ���������ļ�,ֻ����д������.[C11]
"w+x" ����һ���ı��ļ�,�����д.[C11]
"wb+x" ����һ���������ļ�,�����д.[C11]
"w+bx" ��"wb+x"��ͬ[C11]
"rt" ֻ����һ���ı��ļ���ֻ���������
"wt" ֻд�򿪻���һ���ı��ļ���ֻ����д����
"at" ׷�Ӵ�һ���ı��ļ��������ļ�ĩβд����
"rb" ֻ����һ���������ļ���ֻ���������
"wb" ֻд�򿪻���һ���������ļ���ֻ����д����
"ab" ׷�Ӵ�һ���������ļ��������ļ�ĩβд����
"rt+" ��д��һ���ı��ļ����������д
"wt+" ��д�򿪻���һ���ı��ļ��������д
"at+" ��д��һ���ı��ļ���������������ļ�ĩ׷������
"rb+" ��д��һ���������ļ����������д
"ab+" ��д��һ���������ļ���������������ļ�ĩ׷������
��x��β��ģʽΪ��ռģʽ,�ļ��Ѵ��ڻ����޷�����(һ����·������ȷ)���ᵼ��fopenʧ��.�ļ��Բ���ϵͳ֧�ֵĶ�ռģʽ��.[C11]

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