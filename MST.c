void f(){
	system("leaks a.out");
}

int main(){
	/* code */
	atexit(f);
}
