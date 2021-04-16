import java.util.List;

public class Main {
    public static void main(String[] args) {
        GraphImpl graph = new GraphImpl(6);

        Person tom = new Person("Tom");
        Person fred = new Person("Fred");
       Person alice = new Person("Alice");

        graph.addPerson(tom);
        graph.addPerson(fred);
        graph.addPerson(alice);

        graph.makeFriends(tom, fred);
        graph.makeFriends(tom, alice);
        graph.makeFriends(fred, alice);

        // fix removePerson
        // graph.removePerson(tom);

        graph.printGraph();
    }
}
