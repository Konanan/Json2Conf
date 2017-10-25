using UnityEngine;
using System.Collections;
using UnityEditor;
using System.IO;

public class AssetBundleWriter  {

    private string outputFilePath = "";
    private BuildTarget buildTarget = BuildTarget.StandaloneWindows;

    public AssetBundleWriter(string outputPath)
    {
        this.outputFilePath = outputPath;
        AssetDatabase.Refresh();
    }

    public void setBuildPlatform(BuildTarget buildTarget)
    {
        this.buildTarget = buildTarget;
    }

    public void addFile(string path){
        AssetImporter assetBundle = AssetImporter.GetAtPath(path);
        if (null != assetBundle) {
            path = path.Replace(".json", ".conf");
            path = path.Substring(path.LastIndexOf("/") + 1);
            assetBundle.assetBundleName = path;
            assetBundle.assetBundleVariant = null;
        }
        else
        {
            Debug.LogError("cannot create assetbundle " + path);
        }
    }

    public void flush()
    {
        if (Directory.Exists(this.outputFilePath)) {
            Directory.Delete(this.outputFilePath, true);
        }
        Directory.CreateDirectory(this.outputFilePath); 
        BuildPipeline.BuildAssetBundles(
            this.outputFilePath, 
            BuildAssetBundleOptions.ChunkBasedCompression | BuildAssetBundleOptions.DeterministicAssetBundle, 
            this.buildTarget);
        AssetDatabase.Refresh();
        this.removeOtherFiles();
    }

    public void removeOtherFiles()
    {
        var files = Directory.GetFiles(this.outputFilePath);
        foreach (string file in files) {
            if (file.Contains(".manifest")){
                File.Delete(file);
            }
        }

        // delete Json2Conf 
        string json2ConfFile = JsonConf.json2ConfPath + "Json2Conf";
        if (File.Exists(json2ConfFile))
        {
            File.Delete(json2ConfFile);
        }
    }
}
