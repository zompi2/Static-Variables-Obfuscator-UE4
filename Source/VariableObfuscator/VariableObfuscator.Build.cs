// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class VariableObfuscator : ModuleRules
{
	public VariableObfuscator(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(
			new string[]
			{
				"Core"
			}
		);
			
		PrivateDependencyModuleNames.AddRange(
			new string[]
			{
				"CoreUObject",
				"Engine"
			}
		);

		PublicDefinitions.Add("VO_MASK=1254321586");
	}
}
