// Fill out your copyright notice in the Description page of Project Settings.

using UnrealBuildTool;
using System.Collections.Generic;

public class HealthPickupServerTarget : TargetRules //Change this line according to the name of your project
{
    public HealthPickupServerTarget(TargetInfo Target) : base(Target) //Change this line according to the name of your project
    {
        Type = TargetType.Server;
        DefaultBuildSettings = BuildSettingsVersion.V2;
        ExtraModuleNames.Add("HealthPickup"); //Change this line according to the name of your project
    }
}