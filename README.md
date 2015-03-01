gm_cmd
==========

Builds:
-------

| Build Page | Latest Build |
|-------------------------------------------------|--------------------------------------------------------------------------------------------------|
| [Linux](http://build.glua.me/job/gm_cmd_linux/) | [Linux](http://build.glua.me/job/gm_cmd_linux/lastSuccessfulBuild/artifact/bin/gm_cmd_linux.dll) |
| [Windows](http://build.glua.me/job/gm_cmd_win/) | [Windows](http://build.glua.me/job/gm_cmd_win/lastSuccessfulBuild/artifact/bin/gm_cmd_win32.dll) |

Usage:
--------
```lua
require 'cmd'
print(server.exec("ping 8.8.8.8"))
```

![](https://s3-eu-west-1.amazonaws.com/jamie-share/ShareX/2015/03/2015-03-01_08-53-45.png)
![](https://s3-eu-west-1.amazonaws.com/jamie-share/ShareX/2015/03/2015-03-01_08-56-24.png)

Note: You probably shouldn't use this, it'll block the lua thread as there is no threading
