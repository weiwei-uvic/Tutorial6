Arduino:
    - Connect joystick: 
        - GND into GND, 5V into 5V
        - VRx into A0
        - VRy into A1
        - SW into 2
    - Copy the provided code from joystick_code.ino into your Arduino program and upload it to your Arduino
    - Note which COM port is being used (e.g. COM3)
    - This script contains code to read directional inputs from the joystick, and the joystick button press.
    - It will write "UP", "DOWN", "LEFT", "RIGHT", or "BUTTON" to Serial output
    - We will write Unity code to listen to this Serial output and play sounds accordingly

Unity:
    - In the Unity Hub, click "New project", then select the "Universal 2D" template (look under "All Templates"), and click "Create project"
        - This may take a few minutes (~4.5 minutes)
    - In the top bar, click Edit -> Project Settings then search "Api compatibility level" in the top bar
        - Under the "Player" tab, under "Other settings", scroll down a bit to find "API Compatibility Level"
        - By default, this is ".NET Standard 2.1"
        - Change this to ".NET Framework" and close the Project Settings box
        - This allows us to write code which reads Serial communication
    - In "Hierarchy" toolbox on the left:
        - Right click and add an Audio Source (Audio -> Audio Source) and rename it to "Audio Source Drum"
        - Add a second Audio Source and rename it to "Audio Source Music"
        - This will let us play drum sounds and music at the same time
    - In the top bar, click on GameObject -> Create Empty to create a new game object in the scene and 
      rename it to "Manager"
    - Click on the the Manager game object and this should open the Inspector toolbox on the right
        - Click on "Add component", then scroll to the bottom of the options and click on "New script"
        - In the name box, name it "Audio", then click "Create and Add"
    - Now we can edit the script by double clicking the "Audio" C# file in "Project" toolbar at the bottom under
      "Assets" or by clicking the three dots next to "Audio (script)" in the Inspector toolbar then clicking
      "Edit Script"
        - This will open Audio.cs in Visual Studio
        - Copy and paste the provided code from Audio.cs 
        - Save the file and go back to Unity (Unity will update the code)
        - The script contains code to listen to Serial output from Arduino and play sounds depending on the 
          string that is read
    - In the code:
        - Change the "portName" variable to the COM port that your Arduino is using (the code has "COM3" by default)
        - The things to note in the code is:
            - The public AudioClip[] drumSounds, which will be an array of drum audio files
            - The public AudioSource drumPlayer, which will be the Audio Player Drum
            - the public AudioClip[] songs, which we will only have one song in
            - the public AudioSource musicPlayer, which will be the Audio Player Music
        - Since these are public variables, we will assign assets to them in the Unity editor
    - Back in the Unity editor:
        - Click and drag all the provided .mp3 files into the Assets window in the Project toolbar at the bottom
    - Click on the Manager game object. Notice that in the "Inspector" toolbox on the right, the public variables
      we created in the code now appear as boxes which we can drag components into
        - Click on "Drum Sounds" to expand it and you will see "List is empty". We will populate this array with drum sounds.
            - Click the + 4 times to create Element 0 to Element 3
            - From Assets, drag "snaredrum" to Element 0, "hihat" to Element 1, "kickdrum" to Element 2, and
              "crash cymbal" to Element 3
        - Drag "Audio Source Drum" into the "Drum Player"
        - Click on Songs and click + 1 time
            - From Assets, drag "christmas_song" to Element 0
        - Drag Audio Source Music into "Music Player"
    - To make sure that we can hear sounds in Unity, click on any of the audio files in Assets and preview it by clicking on 
      the play button in the bottom right of the Inspector window
        - If no sound is playing, you may need to restart the Unity project
        - Make sure that in your Sound settings -> Volume mixer on your computer, you can see your Unity project (not just Unity Hub)
          as an audio source
        - If you just installed Unity, you may need to restart your computer
    
Using the tool:
    - Click on the play button in the top middle of the unity editor to run your project
    - Make sure your Arduino is also connected at this time
    - Now, you can use directional inputs of the joystick to play drum sounds (up -> crash cymbal, down -> kick drum, 
      left -> snare drum, right -> hi hat)
    - You can click the joystick button to play a christmas song, and click it again to stop it
    - Since we added two audio sources, you can play drums over top of the music
      
        





