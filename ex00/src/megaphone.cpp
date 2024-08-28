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
			cout << line;
		}
		cout << endl;
		}
		else
			cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << endl;
	return 0;
}
