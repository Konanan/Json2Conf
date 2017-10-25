using UnityEngine;
using System.Collections;
using System.IO;
using UnityEditor;

public class JsonConf : MonoBehaviour {
    public static string conf2JsonPath = "Assets/Conf2Json/";
    public static string json2ConfPath = "Assets/Json2Conf/";

    public static void json2Conf(BuildTarget buildTarget)
    {
        var abw = new AssetBundleWriter(JsonConf.json2ConfPath);
        abw.setBuildPlatform(buildTarget);

        var files = Directory.GetFiles(JsonConf.conf2JsonPath);
        foreach (string path in files)
        {
            if (path.Contains(".json") && !path.Contains(".meta"))
            {
                Debug.Log(path);
                abw.addFile(path);
            }
        }
        abw.flush();
    }

    public static void conf2Json()
    {
        // delete directory
        if (Directory.Exists(JsonConf.conf2JsonPath))
        {
            Directory.Delete(JsonConf.conf2JsonPath,true);
        }
        Directory.CreateDirectory(JsonConf.conf2JsonPath);

        var files = Directory.GetFiles(JsonConf.json2ConfPath);
        foreach (string path in files)
        {
            if (path.Contains(".conf") && !path.Contains(".meta"))
            {
                Debug.Log(path);
                JsonConf.loadAssetBundle(path);
            }
        }
    }
    public static void loadAssetBundle(string path)
    {
        string content = AssetBundleReader.loadAsset(path);
        path = path.Replace(".conf", ".json");
        path = path.Substring(path.LastIndexOf("/") + 1);
        FileIO.writeFile(JsonConf.conf2JsonPath + path, content);
    }

}
