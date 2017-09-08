//Run this script at the end of the semester. This moves all current schoolschemas to
//the archive. Change line 4 to the year it will be archived under.
function runArchiveDocuments(){
  addArchiveFolders("2015H");
  archiveDocuments();
}


function archiveDocuments() {
  //Getting our allSchoolsFolder.
  var allSchoolsFolder = DriveApp.getFolderById("0B9gPqniq3sqOZDFXN2gxd1BxeFk");
  //Getting an iterator of all schoolfolders.
  var schoolIterator = allSchoolsFolder.getFolders();

  //variables needed later.
  var fileIterator;
  var schoolFolder;
  var archiveFolder;
  var targetFolder;
  var tmpFile;

  //Iterating over all schoolfolders.
  while (schoolIterator.hasNext()){
    schoolFolder = schoolIterator.next();
    //getting an iterator for the schemas in my school folder.
    fileIterator = schoolFolder.getFiles();
    //Going down the foldertree until the archive folder, and storing
    //that folder in variable targetFolder.
    archiveFolder = schoolFolder.getFolders().next();
    targetFolder = archiveFolder.getFolders().next();

    //Iterating over all the schemas
    while(fileIterator.hasNext()){
      //Storing a schema in tmpfile, then making a copy with
      //an identical name and storing that in my targetFolder.
      //Then I delete the original file.
      tmpFile = fileIterator.next();
      tmpFile.makeCopy(tmpFile.getName(), targetFolder);
      tmpFile.setTrashed(true);
    }
  }
}

function addArchiveFolders(folderName) {
  //Getting our folder with all the schools.
  var allSchoolsFolder = DriveApp.getFolderById("0B9gPqniq3sqOZDFXN2gxd1BxeFk");
  //Getting an iterator for all the schools.
  var schoolIterator = allSchoolsFolder.getFolders();

  var files;
  var tmpFolder;
  var tmpFilee;
  var targetFolder;

  //Iterating over all the schools
  while (schoolIterator.hasNext()){
    //Going down the tree to our target folder, which
    //is the "Arkiverte skjemaer" folder.
    tmpFolder = schoolIterator.next();
    targetFolder = tmpFolder.getFolders().next();
    //Creating a new folder inside targetFolder
    //named whatever was put in line 4.
    targetFolder.createFolder(folderName);
  }

}
