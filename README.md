# Autonomous Vehicle Challenge - A Team
Repository for Autonomous Vehicle Challenge (AVC) by A-Team,
as part of ENGR101 at Victoria University of Wellington

<h2>Members and Roles</h2>

- Ahmed Mohamed (Ahmedmohame1)
    - Hardware (Designing shape of robot and 3D printing, working with others in their hardware-related jobs) 
- Andrew McGhie (mgoo)
    - Networking (Communicating with starting gate) 
    - Module Planning (Planning how the different modules will fit together)
    - Code Integration (Merging all of our code together)
- Benjamin Percy (Radroaches)
    - Tracking (Making robot react to processed information from sensors) 
    - Sensors (Making use of camera sensor information) 
- Daniel Bakes (CenturionBakes)
    - Motors (Making the robot move and coding movement functions) 
- Dylan Chong (dylan-chong)
    - Project Management (Distributing tasks, overseeing project) 
    - Devops (Git management, setting things up and making sure everyone can get started coding)
    - Testing (Making sure each module works before sending to Andrew for integration into project)
- Jonah Ease (dayyad)
    - Sensors (Making use of IR sensor information)
    - Navigation (Algorithms to navigate through the paths)


<h2>Relevant Documents</h2>
- [AVC Project Plan (Read Only)](https://docs.google.com/document/d/1PGjWPlpUhXjcqqKfF3nAxugpQDZaEifs_aqTZwUoJcg/pub)
- [Team Notes (Private Access Only)](https://docs.google.com/document/d/1385G8qHiNDcL0iQiOU0o_waaYvI3Ny60LDWCXVkwYT4/edit?usp=sharing)
- [Elf's Wiki](https://github.com/kaiwhata/ENGR101-2016/wiki)

[//]: **********************************************************************
[//]: **********************************************************************
---
[//]: **********************************************************************
[//]: **********************************************************************


[//]: **********************************************************************
<h2>Progress and Milestones</h2>
[//]: **********************************************************************

<h3>Week 8 (Wed 20 - Sun 24 April) - First Week</h3>




<h4>Milestone Checklist</h4> 
(based off milestones from project plan)

- [x] Everyone: Produce AVC Plan
- [x] Ahmed, Daniel: Get robot to move
- [x] Dylan: Sort out a GitHub repository
- [x] Dylan (+Everyone): Distribute roles

<h4>Minor Task Checklist</h4>
(includes assigned tasks, including small ones, and their progress)

- [x] Andrew: Start writing Networking code
- [x] Ahmed: Begin planning ideas for model
- [x] Ahmed, Daniel: Get motors working
- [x] Ben: Be able to SSH into Pi
- [x] Daniel: Begin making robot move in straight line
- [x] Dylan: Organise team meetings
- [x] Jonah: Start looking up how to convert IR sensor readings into distance

<h4>Daily Log</h4>
<h5>Wednesday 20/04/16</h5>
<h6>Regular Lab</h6>
- Ahmed 
    - Worked on motors with Daniel 
    - Print out sheet to sign (ended up writing signatures on paper and taking photo)
- Andrew 
    - Networking 
        - Wrote code (done) 
- Ben 
    - Found out how to SSH into the pi 
    - Skimmed through avc plan doc and creating todo list for the Project Plan
- Daniel 
    - Movement in straight line 
        - Wrote C++ code (but not tested) 
- Dylan
    - Writing down notes and todos, assigning tasks
    - Github repository
        - Add everyone to a new GitHub repository
        - Created a .gitignore file that blocks Eclipse project files
    - Distributed roles (subject to change) (talked as a group) 
- Jonah 
    - Created google folder with avc plan doc
    - Learning how to use git from Andrew
<!-- /// convert (done) to tickboxes -->

<h6>Working on Project Plan at 8pm (who was there)</h6>
- Andrew 
- Ben 
- Daniel 
- Dylan 
- Jonah

<h5>Thursday 21/04/16</h5>

<h6>Afternoon (extra work)</h6>
- Andrew
	- ??? What did you do Thurs afternoon?

<h6>Working on Project Plan at 730pm</h6>
Andrew 
- Ben 
- Daniel 
- Dylan
- Jonah

<h5>Friday 22/04/16</h5>
<h6>Extra Lab</h6>
- Ahmed
    - Figuring out how to use FreeCAD
    - ???    What progress did you make on this? 
- Daniel 
    - Got motors working
- Dylan 
    - Got git repository working on the pi
    - Added CodeBlocks files to .gitignore file 
- Jonah 
    - ??? What did you do during the lab on Friday

<h6>Extra work)</h6>
- Dylan
	- Merged GitHub branches to get rid of unnecessary movement branches (done) 
	- Reorganised file structure of GitHub repo (done)
- Andrew
	- Created template class and test files

<h5>Saturday 23/04/16</h5>
<h6>Extra work</h6>
- Dylan
	- Moved some files in GitHub

<h5>Sunday 24/04/16</h5>
<h6>Extra work</h6>
- Dylan
	- Added some of the milestone checklist to GitHub readme

<h6>Extra Lab</h6>

<h4>Review</h4>
<!-- /// TODO write up quick review for week 1 -->



[//]: **********************************************************************
---
[//]: **********************************************************************

<h3>Week 9 (Mon 25 - Sun 1 May) - Mid-Trimester Break</h3>



<h4>Milestone Checklist</h4>
- [x] Dylan: Move logs to GitHub readme and have it be up to date

<h4>Minor Task Checklist</h4>
None

<h4>Daily Log</h4>
<h5>Monday 25/04/16</h5>
<h6>Extra work</h6>
- Dylan
	- Moved logs from AVC Team Notes (Google Doc) to GitHub readme
	- Added checklists from Team Notes doc and added tasks for next week
    - Removed all the movement branches from GitHub to prevent anyone from committing to them (I had to merge the movement-straight-line branch and then delete the AVC_movement file to do so).

<h4>Review</h4>
None



[//]: **********************************************************************
---
[//]: **********************************************************************

<h3>Week 10 (Mon 2 - Sun 8 May)</h3>



<h4>Milestone Checklist</h4>
- [x] Everyone, Ahmed: Complete Skeleton robot design (functional parts and structure only)
- [ ] Daniel: Have AVC follow straight lines
- [ ] Ahmed: Create ball bearing for robot
- [x] Andrew, Dylan: Plan modules and methods
- [x] Dylan: Add method stubs to test-module files for others to work on
- [x] Ben: Be able to receive data from camera
- [ ] Jonah: Be able to sense distance from IR sensor

<h4>Minor Task Checklist</h4>
- [ ] Dylan: Record cost of parts so far


<h4>Daily Log</h4>

<h5>Wednesday 04/05/16</h5>
- Dylan
    - Got the camera temporary code working (copied from the Kaiwhata wiki) and can remotely compile and run it
    - Made a template for the IR sensor (individual project) for Jonah
    - Began planning how the main loop will work

<h5>Thursday 05/05/16</h5>
- Andrew
    - Worked with Dylan on Plan (see Dylan's entry)
- Dylan
    - Planned a lot more of the main loop, this time planning out how it will fit with different classes
    - Worked with Andrew on the main loop plans/how everything fits together (plan completed for now)

<h5>Friday 06/05/16</h5>
- Dylan
	- Moved method stubs, that I planned with Andrew yesterday, into the test modules for others to implement.
    - Planned some basic outline code for tracking algorithm

<h4>Review</h4>
- Position of sensors have been planned
- Motor code is still in progress (motors do work, buthave been disconnected)
- We may not need a ball bearing - we will decide later if we need it (not crucial)
- Modules have been planned 
- Method stubs have been added to test-module files
- The camera works, but algorithm in progress
- IR Sensor code is still in progress (need catch up)

Extra Info

- Ahmed has been able to print off some parts to attach sensors to, and get some recycled parts to hold the robot

[//]: **********************************************************************
---
[//]: **********************************************************************

<h3>Week 11 (Mon 9 - Sun 15 May)</h3>



<h4>Milestone Checklist</h4>
- [ ] Ahmed: Produce body prototype
- [ ] Andrew: Robot can successfully talk to gate
- [ ] Ben: Data from camera is processed to give information on the line
- [ ] Daniel: Robot can follow curved lines
- [ ] Dylan: Robot can be in different states

<h4>Minor Task Checklist</h4>

<h4>Daily Log</h4>
<h5>Monday 09/05/16</h5>
- Dylan
	- Had a look at Ben's code, tidied it up, and tested it (stuck in a loop somewhere)

<h4>Review</h4>



[//]: **********************************************************************
---
[//]: **********************************************************************

<h3>Week 12 (Mon 16 - Sun 22 May)</h3>



<h4>Milestone Checklist</h4>
- [ ] Everyone: Robot is complete
- [ ] Ahmed: 3D Print body design and add it to the robot
- [ ] Dylan: Robot is tested


<h4>Minor Task Checklist</h4>

<h4>Daily Log</h4>

<h4>Review</h4>

