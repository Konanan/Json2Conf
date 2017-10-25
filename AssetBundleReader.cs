using UnityEngine;
using System.Collections;

public class AssetBundleReader  {

    public static string loadAsset(string path)
    {
        var assetBundle = AssetBundle.LoadFromFile(path);
        var assetNames = assetBundle.GetAllAssetNames();
        for (int i = 0; i < assetNames.Length; i++)
        {
            Debug.Log(assetNames[i]);
        }

        Object obj = assetBundle.LoadAsset(assetNames[0]);
        TextAsset ta = obj as TextAsset;
        assetBundle.Unload(false);
        return ta.text;
    }
}
