#include <string>
#include <iostream>
#include <vector>

int file_mmap(const std::string& map_file_name, vector<std::string>& vecBill)
{
	void *memory = NULL;
	//char *data = NULL;
	int file_length = 0;
	int fd = open(map_file_name.c_str(), O_RDONLY);
	if (fd < 0)
	{
		printf("file open [%s] error\n", map_file_name.c_str());
		return -1;
	}
	file_length = lseek(fd, 0, SEEK_END);
	//data =(char*)mmap(NULL,file_length,PROT_READ,MAP_SHARED,fd,0);
	memory = mmap(NULL, file_length, PROT_READ, MAP_SHARED, fd, 0);
	//printf("memory = %s\n", (char *)memory);
	split_ex((char *)memory, '\n', vecBill);
	/*for (int i = 0; i < vecBill.size(); ++i)
	{
		printf("i = %d value= %s\n", i, vecBill[i].c_str());
	}*/
	close(fd);
	munmap(memory, file_length);
	return 0;
}

