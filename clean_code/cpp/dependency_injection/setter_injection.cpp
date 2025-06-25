class Abhängiges {
  private Abhängigkeit abhängigkeit;

  public void setAbhängigkeit(final Abhängigkeit abhängigkeit) {
    this.abhängigkeit = abhängigkeit;
  }
}

// A central component is responsible to create the dependencies during runtime.
class Injizierer {
  void methode() {
    final Abhängiges abhängiges = ... ;
    final Abhängigkeit abhängigkeit = ... ;
    abhängiges.setAbhängigkeit(abhängigkeit);
  }
}
