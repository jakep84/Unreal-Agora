// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

using System.IO;

public class AgoraPlugin : ModuleRules
{
	public AgoraPlugin(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;
		
		PublicIncludePaths.AddRange(
			new string[] {
				// ... add public include paths required here ...
            }
			);

        string ParentModuleDirectory = Directory.GetParent(ModuleDirectory).ToString();
        string IncludeDir = Path.Combine(ParentModuleDirectory, "ThirdParty/libyuv/include/");
		PrivateIncludePaths.AddRange(
			new string[] {
				// ... add other private include paths required here ...
                IncludeDir
            }
			);
			
		
		PublicDependencyModuleNames.AddRange(
			new string[]
			{
				"Core",
				"Agora",
                "libyuv",
                "Projects"
				// ... add other public dependencies that you statically link with here ...
			}
			);
			
		
		PrivateDependencyModuleNames.AddRange(
			new string[]
			{
				// ... add private dependencies that you statically link with here ...	
			}
			);
		
		
		DynamicallyLoadedModuleNames.AddRange(
			new string[]
			{
				// ... add any modules that your module loads dynamically here ...
            }
			);

        if(Target.Platform == UnrealTargetPlatform.Mac)
        {
            PublicAdditionalLibraries.Add ("resolv");

            PublicFrameworks.AddRange(
                new string[] {
                    "AppKit",
                    "IOKit",
                    "CoreVideo",
                    "CFNetwork",
                    "OpenGl",
                    "CoreGraphics",
                    "Accelerate",
                    "CoreFoundation",
                    "SystemConfiguration",
                    "AudioToolbox",
                    "VideoToolbox",
                    "CoreTelephony",
                    "CoreWLAN",
                    "AVFoundation",
                    "CoreMedia",
                    "CoreAudio"
                });
        }
	}
}
