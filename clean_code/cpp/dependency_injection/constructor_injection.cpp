class Abhängiges {
  private Abhängigkeit abhängigkeit;

  //Konstruktor
  public Abhängiges(final Abhängigkeit abhängigkeit) {
    this.abhängigkeit = abhängigkeit;
  }
}

class Injizierer {
  void methode() {
    final Abhängigkeit abhängigkeit = ... ;
    final Abhängiges abhängiges = new Abhängiges(abhängigkeit);
  }
}

class Dependent
{

	// Constructor
	public:
		Dependent(Dependency dependency)
		{
			this.dependency = dependency;
		}

	private:
		Dependency dependency;

}

class Injector
{
	void method()
	{
		Dependency dependency = ... ;
		Dependent dependent = new Dependent(dependency);
	}
}
