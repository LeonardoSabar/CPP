#include "../include/megaphone.hpp"

using namespace std;

int	main(int argc, char **argv)
{
	if (argc > 1)
	{
		string	line;
		unsigned long words;
		for (words = 1; argv[words] != '\0'; words++)
		{
			line = argv[words];
				transform(line.begin(), line.end(), line.begin(), ::toupper);
			// unsigned long i;
			// for(i = 0 ; i < line.length(); i++)
			// {
			// 	if (line[i] >= 'a' && line[i] <= 'z')
			// 		line[i] = line[i] - 32;
			// }
			cout << line;
		}
		cout << endl;
		}
		else
			cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << endl;
	return 0;
}
