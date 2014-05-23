# GhostAWT

GhostAWT is a Java library for running Java Swing/AWT applications on headless environments like Servers and NAS-Systems.

## The Problem

If you try to run Java GUI applications on environments without a Graphical User Interface you will have an XServer to be installed on the system, but often you do not want to install an XServer, Xvfb or a VNC Server on your System for only running a particular Java application which has a User Interface. That's where GhostAWT comes in place.

## The Solution

Since Java is a multiplatform language there must be some sort of platform abstraction, and there is. GhostAWT is an implementation of that abstraction layer for headless environments. GhostAWT provides an empty implementation for all AWT and Java2D operations which makes any Java AWT or Swing application believe that there is a Graphicsl User Interface available on the system. 

There is already a mechanism in Java called [Headless Mode](http://www.oracle.com/technetwork/articles/javase/headless-136834.html). But if you try to create any UI Components, you just get a `HeadlessException` which prevents you from proceeding. Using GhostAWT you can bypass this problem and create AWT and therefore Swing Component instances without a window system.

## Usage 

1. Download the GhostAWT packages from the [releases](https://github.com/Danielku15/GhostAWT/releases)
2. Place GhostAWT beside your Java Application
3. Start your Java Application using a commandline similar to this: 

```
java -Dawt.toolkit=ghostawt.GhostToolkit -Djava.awt.graphicsenv=ghostawt.image.GhostGraphicsEnvironment -Djava.awt.headless=false -Dsun.font.fontmanager=ghostawt.sun.GFontManager -cp "./*" my.main.Application
```

### Explaination

`-Dawt.toolkit=ghostawt.GhostToolkit` - Makes Java use the Ghost AWT Toolkit implementation 

`-Djava.awt.graphicsenv=ghostawt.image.GhostGraphicsEnvironment` - Makes Java use the Ghost Java2D implementation for graphic operations

`-Djava.awt.headless=false` - Ensures the headless-detection mechanism of Java does not think we are on a headless environent

`-Dsun.font.fontmanager=ghostawt.sun.GFontManager` - Makes Java use the Ghost Font Manager for loading system fonts
