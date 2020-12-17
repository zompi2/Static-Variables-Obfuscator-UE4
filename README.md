# Static Variables Obfuscator UE4

This code plugin for Unreal Engine 4 obfuscates any static (non-dynamic) variable so it is very difficult to locate this variable in the memory.

This makes using tools like Cheat Engine to manipulate in-game data a non trivial task.

## How to use it?

Simply wrap a declared variable with TVarOb keyword and it will obfuscate it.

``` cpp
int32 X;            // Not obfuscated variable :(
TVarOb<int32> Y;    // Obfuscated variable :)
```

Obfuscated variable can be manipulated in the same manner as normally

``` cpp
TVarOb<int32> X = 1;    // Assing variable
X += 10;                // Increase variable
int32 Y = X;            // Get variable
```

## Using it with structs

Unfortunatelly to modify obfuscated struct it has to be unencrypted first.

``` cpp
struct FSomeStruct
{
    int32 X;
};

TVarOb<FSomeStruct> Foo;

FSomeStruct Bar = Foo;
Bar.X += 10;
Foo = Bar;
```

## What types are supported?

Currently it supports all arithmetic types and the following structures:

* FTransform
* FVector
* FVector2D
* FRotator
* FQuat
* FColor
* FLinearColor

Theoretically it should work with any struct that doesn't contain dynamic variables (pointers, strings, arrays, etc). However it implements a check to ensure only verified structures are used. If You want to You can add a proper trait check to the `VarObSupportedTypes.h`.

## Blueprints

This plugin works the best with code but there are some structures and functions that allows to use it with Blueprint too. For more details check `VarObBPLib.h` file.