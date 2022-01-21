// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class MobileTopView : ModuleRules
{
	public MobileTopView(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

        PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "HeadMountedDisplay", "NavigationSystem", "AIModule" });
    }
}
