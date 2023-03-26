
Param (
    [Parameter(Mandatory=$true)]
    $BuildTargetFolder,
    [Parameter(Mandatory=$true)]
    $BuildTargetFile)
    
echo $BuildTargetFile
echo $BuildTargetFolder

taskkill /IM "S4_Main.exe" /F > $null 2> $null

$S4Path = Get-ItemPropertyValue -Path Registry::HKEY_LOCAL_MACHINE\SOFTWARE\WOW6432Node\Ubisoft\Launcher\Installs\11785 -Name InstallDir
$PluginPath = "${S4Path}plugins"

$BuildTargetFile = "${BuildTargetFolder}${BuildTargetFile}"

echo "${BuildTargetFile}.nasi"
echo "$PluginPath"
Copy-Item -Path "${BuildTargetFile}.nasi" -Destination "$PluginPath" -Force