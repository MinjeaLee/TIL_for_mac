public static int mystery(Scanner console) { 
	int prev = 0; 
	int count = 0; 
	int next = console.nextInt(); 
	// Point A 
	while (next != 0) { 
		// Point B 
		if (next == prev) { 
			// Point C 
			count++; 
		} 
		prev = next; 
		next = console.nextInt(); 
		// Point D 
	} 
	// Point E 
	return count;
}