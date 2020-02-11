# AgoraVideoCall

The Agora Video Call is a demo app that will help you get video chat integrated directly into your Unreal Engine applications using the AgoraPlugin, that wraps Agora Video SDK.

With this sample app, you can:

- Join / leave channel
- Mute / unmute audio
- Enable / disable video
- Switch camera
- Setup resolution and frame rate 

Developed with Unreal Engine 4.23

## Building and running the App

Open AgoraVideoCall.uproject with Unreal Editor( version no less than 4.23 ).

To package the project:

1) File->Package Project->Windows->Windows(64-bit) then select a folder where you want to package and wait for result.

![Alt text](HowTo/HowToPackageProject.png?raw=true "PackageProject")
![Alt text](HowTo/HowToPackageProjectMac.png?raw=true "PackageProject")

2) Now need to package the plugin. 

Edit->Plugins-> Skip Built-In plugins and scroll down to "Project", click on "Other" to find "AgoraPlugin", then "Package", and select the folder inside the packaged project:
(Packaged project dir)/WindowsNoEditor/AgoraVideoCall/Plugins/AgoraPlugin/.

![Alt text](HowTo/HowToPackagePlugin.png?raw=true "PackagePlugin")

3) Now you can find executable file of the demo App in the folder selected on step (1) and run the App.

## Supported platforms

Windows 64-bit

Mac

## Use the plugin in your project

1. Copy the plugin to [your_project]/Plugins
2. Add plugin dependency into .Build.cs, Private Dependencies section

`PrivateDependencyModuleNames.AddRange(new string[] { "AgoraPlugin" });`

## Connect Us

- You can find full API document at [Document Center](https://docs.agora.io/en/)

### Third party

libyuv

In the folder: 
AgoraVideoCall/Plugins/AgoraPlugin/Source/ThirdParty/libyuv
need to place libyuv headers and .lib file( .a file for Mac )
include/
x64/Release/yuv.lib
Mac/Release/libyuv.a

In case of problems with building yuv on Mac caused by jpeg, just disable jpeg in CMakeLists.txt

## Mac permissions

Add the following permissions in the info.plist file for device access:

Privacy - Camera Usage Description

Privacy - Microphone Usage Description

