// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class MOLURANTCPP : ModuleRules
{
	public MOLURANTCPP(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] {
			"Core",
			"CoreUObject",
			"Engine",
			"InputCore",
			"EnhancedInput",
			"AIModule",
			"StateTreeModule",
			"GameplayStateTreeModule",
			"UMG",
			"Slate",
			"NavigationSystem"
		});

		PrivateDependencyModuleNames.AddRange(new string[] { });

		PublicIncludePaths.AddRange(new string[] {
			"MOLURANTCPP",
			"MOLURANTCPP/Variant_Horror",
			"MOLURANTCPP/Variant_Horror/UI",
			"MOLURANTCPP/Variant_Shooter",
			"MOLURANTCPP/Variant_Shooter/AI",
			"MOLURANTCPP/Variant_Shooter/UI",
			"MOLURANTCPP/Variant_Shooter/Weapons"
		});

		// Uncomment if you are using Slate UI
		// PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });

		// Uncomment if you are using online features
		// PrivateDependencyModuleNames.Add("OnlineSubsystem");

		// To include OnlineSubsystemSteam, add it to the plugins section in your uproject file with the Enabled attribute set to true
	}
}
