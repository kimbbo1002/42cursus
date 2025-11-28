#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>


int main(int argc, char **argv)
{
	int		fd;
	char	*line;
	int		line_count;

	if (argc != 2)
	{
		printf("Usage: %s <filename>\n", argv[0]);
		return (1);
	}

	// Open the file
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		perror("Error opening file");
		return (1);
	}

	// Read and print each line
	line_count = 1;
	printf("\n========== READING FILE: %s ==========\n\n", argv[1]);
	
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("Line %d: [%s]\n", line_count, line);
		free(line);
		line_count++;
	}
	
	printf("\n========== END OF FILE (Total lines: %d) ==========\n\n", line_count - 1);

	// Close the file
	close(fd);

	// Test reading again after EOF
	printf("Testing second read (should return NULL):\n");
	line = get_next_line(fd);
	if (line == NULL)
		printf("✓ Correctly returned NULL after EOF\n\n");
	else
	{
		printf("✗ ERROR: Returned non-NULL after EOF: [%s]\n\n", line);
		free(line);
	}

	return (0);
}
