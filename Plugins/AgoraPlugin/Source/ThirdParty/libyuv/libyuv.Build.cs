//  Copyright (c) 2019 Agora.io. All rights reserved.

using System.IO;
using UnrealBuildTool;

public class libyuv : ModuleRules
{
	public libyuv(ReadOnlyTargetRules Target) : base(Target)
	{
		Type = ModuleType.External;

		if (Target.Platform == UnrealTargetPlatform.Win64)
		{
			// Add the import library
			PublicLibraryPaths.Add(Path.Combine(ModuleDirectory, "x64", "Release"));
			PublicAdditionalLibraries.Add("yuv.lib");
        }
        else if (Target.Platform == UnrealTargetPlatform.Mac)
        {
            PublicAdditionalLibraries.Add(Path.Combine(ModuleDirectory, "Mac", "Release", "libyuv.a"));
        }
	}
}

