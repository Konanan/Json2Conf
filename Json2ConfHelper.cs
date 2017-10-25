using UnityEngine;
using System.Collections;
using UnityEditor;
using System.IO;


public class Json2ConfHelper : EditorWindow
{

    private static string conf2JsonPath = "Assets/Conf2Json/";
    private static string json2ConfPath = "Assets/Json2Conf/";

    private int platformIndex = 0;

    [MenuItem("Json2Conf/Show Window")]
    public static void build()
    {
        Debug.Log("build asset bundle !!!");

        Json2ConfHelper window = CreateInstance<Json2ConfHelper>();
        window.titleContent = new GUIContent("Json2Conf");
        window.Show();
    }

    void OnGUI()
    {
        GUILayout.Label("使用说明：");
        GUILayout.TextArea("建立Assets/Json2Conf/和Assets/Conf2Json/文件夹\nJson2Conf放入.conf文件\nConf2Json放入.json文件\n可相互转换");

        platformIndex = GUILayout.Toolbar(platformIndex, new string[] { 
            "Android",
            "iOS",
            "Windows",
            "Mac OS X"
        });

        if(GUILayout.Button("Json2Conf"))
        {
            JsonConf.json2Conf(this.getBuildTarget());
        }

        if (GUILayout.Button("Conf2Json"))
        {
            JsonConf.conf2Json();
        }
    }

    BuildTarget getBuildTarget()
    {
        if (0 == this.platformIndex)
        {
            return BuildTarget.Android;
        }
        else if (1 == this.platformIndex)
        {
            return BuildTarget.iOS;
        }
        else if (2 == this.platformIndex)
        {
            return BuildTarget.StandaloneWindows64;
        }
        else if (3 == this.platformIndex)
        {
            return BuildTarget.StandaloneOSXIntel64;
        }
        else
        {
            return BuildTarget.StandaloneWindows64;
        }
    }

}
