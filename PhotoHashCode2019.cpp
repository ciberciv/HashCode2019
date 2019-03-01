// Attempt to solve the HashCode2019 challenge. All that could be done in time

#include <string>
#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <malloc.h>
using namespace std;


// Useful structs

struct Photo{
  char pos;
  int nTag;
  string* tags;
};

struct TagsShared{
  string* tagsShared;
  int nTag;
};


// Takes two photos, returns common tags

TagsShared GetCommonTags(Photo& firstPhoto, Photo& secondPhoto){
  TagsShared commonTags;
  commonTags.nTag = 0;

  for (int i = 0; i < firstPhoto.nTag; i++) {
    for (int j = 0; j < secondPhoto.nTag; j++) {
      if (firstPhoto.tags[i] == secondPhoto.tags[j]){
        commonTags.nTag++;
      }
    }
  }

  commonTags.tagsShared = new string[commonTags.nTag];
  int count = 0;

  for (int i = 0; i < firstPhoto.nTag; i++) {
    for (int j = 0; j < secondPhoto.nTag; j++) {
      if (firstPhoto.tags[i] == secondPhoto.tags[j]){
        commonTags.tagsShared[count] = firstPhoto.tags[i];
        count++;
      }
    }
  }

  return commonTags;
}


// Reads the competition files

Photo ReadFromFile(ifstream & myReadFile){
  Photo photo;
  string nTagstr;
  myReadFile >> photo.pos;
  myReadFile >> nTagstr;
	photo.nTag = stoi(nTagstr);

	// Gets all tags in the array
	photo.tags = new string[photo.nTag];
	for (int i = 0; i < photo.nTag; i++)
	{
		myReadFile >> photo.tags[i];
	}

	return photo;
}

int main()
{
	// Get array size
	int N;
	string Nstr;
	ifstream myReadFile;							// Open text file
	myReadFile.open("BLOCA.txt");
	myReadFile >> Nstr;
	N = stoi(Nstr);

	// Create photo array
	Photo* photo = new Photo[N];

	for (int i = 0; i < N; i++)
	{
		photo[i] = ReadFromFile(myReadFile);
	}

	// Print tags
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < photo[i].nTag; j++)
		{
			cout << photo[i].pos << " . " << photo[i].tags[j] << "\n";
		}
	}

	// GetCommonTags test with photos 1 and 2
	TagsShared commonTags = GetCommonTags(photo[1], photo[2]);

	for (int i = 0; i < commonTags.nTag; i++) {
		cout << commonTags.tagsShared[i] << endl;
	}

	system("pause");
	return 0;
}
