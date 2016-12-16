#include "File.h"
#include <stdio.h>
#include <string>
#include <assert.h>

unsigned char* File::getFileData(const char* pszFileName, const char* pszMode, unsigned long * pSize)
{
    unsigned char * pBuffer = NULL;
    assert(pszFileName != NULL && pSize != NULL && pszMode != NULL, "Invalid parameters.");
    *pSize = 0;
    do
    {
        // read the file from hardware
        FILE *fp = fopen(pszFileName, pszMode);
		if(!fp){
			break;
		}
        
        fseek(fp,0,SEEK_END);
        *pSize = ftell(fp);
        fseek(fp,0,SEEK_SET);
        pBuffer = new unsigned char[*pSize];
        *pSize = fread(pBuffer,sizeof(unsigned char), *pSize,fp);
        fclose(fp);
    } while (0);
    
    if (! pBuffer)
    {
        std::string msg = "Get data from file(";
        msg.append(pszFileName).append(") failed!");
		printf("%s", msg.c_str());
    }
    return pBuffer;
}

bool File::writeData(unsigned char* data,const char *path, const char* pszMode, unsigned long pSize)
{
	do{
        std::string fullPath = path;
        FILE *fp = fopen(fullPath.c_str(), pszMode);
		if(!fp){
			return false;
		}

		fwrite(data,sizeof(unsigned char),pSize,fp);
		fclose(fp);
	}while (0);
	return true;
}
