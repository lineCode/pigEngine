# 21/1/2016
Now I'm making the abstract factory for characters, and then I'll make them work and that.
Isn't it lovely when you find something you didn't even know you had to do? <3

# 19/1/2016
Ok I think regions are kinda done although actually they need more stuff done. then it's
time to finish off characters and their two types. once that's done I can make the
converter. how exciting that it is actually in sight considering how this part has been
a major pain in the dick. At least the fighting part won't have as many little fiddly
features.

# 11/1/2016
before I can make the thing that converts tiled maps into my maps, I have to have created
a fair bit of the map functionality. The next thing I should do is add named regions that
can activate events when entered, and also can be teleported into with a vm addon.

# 8/1/2016
don't need to worry about abstract factories for tile maps or characters or anything, so
therefore I can just add a function to create these based on a file name and then it can
read them from a binary file just like in the good old days.
yeah and get rid of tilesets.
 - Kill a man

# 6/1/2016
More specific details on how characters will be stored and that type of thing:
 - there are two kinds of data that characters contain, the static kind that belong on
   pages, and the changeable kind like position, velocity and stuff.
 - each page will also contain a set of conditions that must be met in order to reach this
   page, each condition will be made up of two variables or constants, and a thing that
   turns them into a boolean value like =,!=,> etc.
 - each page also contains a script that will be triggered by a few different conditions,
   such as player pressing a button while next to them, or as soon as the player bumps
   into them and stuff like that.
 - in order to make it more efficient, characters will only decide which page they are on
   at the start of the level, and then whenever a special function is called to make them
   all recheck, which can be called whenever an event occurs that should cause something
   to happen.


I really don't want to have to create a whole rpgmaker rip off since it would make me
want to die, so I think I need to rethink the way tilesets and that work to make it less
reliant on configuration. I'll just make it that the bottom layer of each level is the
collision detection level, and some other thing can determine layers that appear above
the player's head. That's how I normally do it anyway.

Also I think I'll add teleportation regions. I know it kinda clashes with having rpgmaker
style characters, but it should be fast and easy, so that's good


# 4/1/2016
keep working on this stream reader thing so that I can actually read in files properly
to make the factories work.

at some point I should make some class that takes care of rendering for the user, not
only would it be nicer, but it could also contain the screen height and stuff which would
be good rather than storing it in assets. one day...

Ok stream reader and backgrounds work nicely, so now what...
I beleive it is now about time I started work on overworld scene. I'll probably find a
million other things to do in the process, but that's ok.

So it is going to need to have characters which do walk around and can be talked to. also
maybe some can be activated simply by being stepped up to, so that they can act as doors
and stuff. as far as talking goes they will simply be running a script that does stuff,
however, in order to make them walk around I will need yet another new system, but I think
I will just make up an enum of directions/ways they can move, and then make their list of
movements be stored in a vector or something. oh yeah another thing is that characters
will need to be able to basically completely changed depending on their personal variables
and also global variables. that could be quite hard to write in nicely so that it isn't
unweildly but also isn't inefficient. probably it will need to be some kind of script.

no wait it won't need to be a script, it will just be some kind of thing where before each
character sheet you specify the variable and it's value in order for this sheet to be able
to go, but if many sheets are ready to go, the latest one wins. I guess it should be that
it's between two values so that way you can do <,>,<=,>=, and =, though sadly not != but
whatever.

yeah so that will work well, then I just need to add a few other features and that will
basically be the overworld done!!!!!!!!!!!!!!!!!!

# 3/1/2016
ok now I need to make new kinds of scene that make sense for this new world, I probably
can replace all menus with some kind of scene that runs a script and has a picture in
the background. I will call it static scene or something.

This means that I now need to make background factories so that you can create the
background for this kind of scene. I'll need to make it that AbstractFactory can take a
istream as well as a filename so that I can create those nice composite types of things.

# 30/12/2015
ok fiendicans first I am going to add a vm addon for changing the current scene, then I
need to make the scene factory thingo that will allow you to load the correct scene from
a file yeeeeaaaaaaah. actually I should prob make the factory first.

ok since I'll need to do this for other things as well I should make this nice and
adaptable.
 - it'll need to be an abstract factory, but each sub factory thing can just be a functor
 and each subclass of scene will register it's functor and name with the super factory
 which will be stored in Scene.hh. this way the main factory can just be a template type.

# 28/12/2015
working on creating the question boxes. maybe instead of having the questions written
as separate strings, i should just separate them with a slash or something, otherwise
i'd need to provide the number of arguments twice. forget a slash, just use different
arguments in the script and then they will just have the null character between them.
no wait they'll still need something at the end, maybe a final special string that tells
us there will be no more.

# 27/12/2015
Ok, so I need to make windows and stuff look nice which will require two things, I will
need to make it that they are placed in correct positions and sizes on the screen, and
then also I need to make window skins, they will not need to be a type of asset, and
can simply be images which may or may not be wrapped in another class, but there will
need to be a data file telling the game what the window skin images are.

apparantly I need to redo adding controllers to the game to make it work as a desktop
program.

# 26/12/2015
looks like it won't work as html5. so it's just a desktop app now!! need to make it that
it runs at a regular framerate, then I guess it's back to business.
Everything is going bloody swimmingly. next thing to do is actually make the gui system
work so that I can test it with the script system.

# 25/12/2015
lol, it's christmas.
Yeah but anyway i'm still going to make it that the Makefile copies in the the files
from some nice directory, then it builds, then they are removed again. NICE!
awwwwwwwwwwwwwww yeah It's working pretty DAMN(tm) nicely.

# 21/12/2015
I need to make danylib and pigscript build to emscripten's bytecode, but at the moment
they seem to be unable to even detect header files. perhaps I need to make them be js
files or something like that. or perhaps bc file.
This is hella annyoing, anyway the worst case is just that I have to copy and paste these
files into pig Engine, actually a good idea would be to temporarily copy them in using
the make file or something. yeah i'll copy in the .bc files or something and the header
files since i need those I guess. I can put them in their own special directories that
say that they are what they are yea heayh.

# 20/12/2015
so the scene needs to be accessable to the addon functions since they do stuff to it, but
I can't just make it available everywhere. maybe you initialize the addon file, providing
a pointer to a pointer to the scene, so that when it changes they will still have it.
also make it that logic no longer returns the next scene, it will be done exclusively by
scripts that change it for the base scene class.

ok one better is I will create a game state object which belongs to main, but is also
given to the addon file when it is initialised!!!!!!!!

# 19/12/2015
make the basic scene class contain the functionality to contain GUI windows. To run the
scripts there will have to be a central virtual machine since it'll contain all the addon
functions and that. the only problem there is they will need access to the current scene,
so perhaps I can put the virtual machine and the current scene in some header file with a
bunch of game constants like the screen height and stuff.
OR I can just provide a pointer to a pointer to the current scene and make sure they
don't try any funny business. yeah so then the addons just get the current scene and do
whatever they desired with it, and then when they are done they return so that the script
may carry on. they can block for ages though if they want I guess.

# 18/12/2015
Next thing I must do is make it that you can set the controls for controllers since they
seem to do weird shit by default.
OKKKK SO WHat needs to jhapend is for the menu scene to use the new gui stuff so I can see
if it worksssssssssss yeaewa. other than that yeee it all seems pretty goodd ayyyy.

# 10/12/2015
Make managers use C file io instead of c++, I'm pretty sure it'll make the compiled
program smaller and anyway I like it better.
For some reason it's saying that all the stuff I define in assets.hh is multiply defined,
I'll have to figure that out tomoroow. nah fixed it, they have to be extern for some
reason. Anyway, that's all the new errors ironed out. Next thing I have to do is get the
gui system working with the scripting system that I made.

# 9/12/2015
Ok zippitty zoopers today we have the problem of emscripten not seeming to know about the
mixer. This might be some kind of thing where I need to do more configuration on emcc, so
a google search is probably in order there.

# 8/12/2015
Move the item loading functors back to assets because they rely on assets and also they
are not necessarily essential to the original item's type and that.
 - maps will be loaded as needed.
 - tilesets are managed

Geany is still making backup files when I don't want it to, I'll have to fix that. Also
If I can get a terminal emulator that runs in this window that would be pretty cool cos
then I can run everything from inside this pretty much.


# 7/12/2015
god damn fix up the Manager.hh weirdness and then make tilemap work.

# 2/12/2015
Ok so now that the scripting language has been implemented, alhtough not integrated, it's
time to get back to the real engine. the first thing to do it make the overworld scene
appear, then we add characters, control them with a gamepad or keyboard, and also the
npc characters must be controlled also.
Then it's time to integrate the scripting language.
