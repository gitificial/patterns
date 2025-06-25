

interface Injizierbar {
  void injiziere(final Abhängigkeit abhängigkeit);
}

class Abhängiges implements Injizierbar {
  private final Abhängigkeit abhängigkeit;

  public void injiziere(final Abhängigkeit abhängigkeit) {
    this.abhängigkeit = abhängigkeit;
  }
}

class Injizierer {
  void methode() {
    final Abhängigkeit abhängigkeit = ... ;
    final Injizierbar abhängiges = ... ;
    abhängiges.injiziere(abhängigkeit);
  }
}
