using UnityEngine;
using System.Collections;
using System.IO;

public class FileIO  {

    /* 读取文件
 * fileName 读取文件的全路径 
 */
    public static string readFile(string fileName)
    {
        string fileContent = "";
        using (StreamReader sr = new StreamReader(fileName))
        {
            fileContent = sr.ReadToEnd();
            sr.Close();
        }
        return fileContent;
    }

    /* 写入文件
     * fileName 文件全路径
     * content 写入文件的内容
     */
    public static bool writeFile(string fileName, string content)
    {
        using (StreamWriter sw = new StreamWriter(fileName))
        {
            sw.Write(content);
            sw.Flush();
            sw.Close();
        }
        Debug.Log("write file end " + fileName);
        return true;
    }
}
