# Data Manager Plugin for Unreal Engine 5

**Data Manager** is a lightweight Unreal Engine 5 plugin designed to streamline data retrieval by leveraging the Gameplay Tags system. It offers a clean and maintainable alternative to loading objects with hardcoded paths, empowering developers to reference assets and data rows through tag-driven identifiers.

## 💡 Features

- **Tag-Based Lookup** – Link Gameplay Tags directly to Data Tables and rows.
- **Flexible Content Access** – Retrieve engine content at runtime without hardcoded asset paths.
- **Cleaner Codebase** – Eliminate fragile references and reduce coupling in asset management.
- **Editor Support** – Built with intuitive editor integration for tag assignment and validation.

## 🚀 How It Works

1. Create the Data Manager Lookup Asset deriven from ```UDataManagerLookupAsset``` in Engine.
3. Register the Data Manager Lookup Asset via DefaultGame.ini.
```
[/Script/DataManager.DataManagerSubsystem]
LookupAssetPath=/Game/Your/Chosen/Directory/DA_DataManagerLookup.DA_DataManagerLookup
```
4. Register Data Tables in the Data Manager Lookup Asset.
5. Query for content using Gameplay Tags:
```cpp
UDataManagerSubsystem::GetData<FRowStruct>(ExampleGameplayTags::Data_Category_LevelData, ExampleGameplayTags::Level_Menu);
```

Behind the scenes, the Data Manager maps a tag to a registered Data Table and a tag to a row, returning the desired struct instance.

## 🧩 Use Cases

- Dynamic item data lookups in RPGs or shooters
- Runtime customization systems based on tagged content
- Rapid iteration without changing compiled code

## 📦 Installation

1. Clone or download the plugin into your project’s `Plugins` folder.
2. Enable the plugin via `Edit > Plugins > Data Manager`.
3. Restart the editor and configure your tag-to-table mappings.

## 📘 Documentation
Coming soon: full API documentation, usage examples, and blueprint nodes.
