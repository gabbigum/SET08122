import java.util.List;
import java.util.Map;

// Adjacency matrix graph
public class GraphImpl {

    // graph api
    // add new vertice(friend)
    // remove vertice(friend)
    // calculate degree of any node
    // find all friends of somebody

    private int vertices;
    private int[][] matrix;

    private Person[] personPosition;

    public GraphImpl(int vertices) {
        this.vertices = vertices;
        matrix = new int[vertices][vertices];
        personPosition = new Person[vertices];

        for (int i = 0; i < vertices; i++) {
            for (int j = 0; j < vertices; j++) {
                matrix[i][j] = 0;
            }
        }
    }

    public void addPerson(Person person) {
        for (int i = 0; i < personPosition.length; i++) {
            if (personPosition[i] == null) {
                personPosition[i] = person;
                break;
            }
        }
    }

    public void removePerson(Person person) {
        int personIndex = getPersonIndex(person);
        personPosition[personIndex] = null;
        // shift person positions
        for (int i = personIndex; i < personPosition.length - 1; i++) {
            personPosition[i] = personPosition[i + 1];
        }

        for (int i = personIndex; i < vertices - 1; i++) {
            for (int j = 0; j < vertices - 1; j++) {
                matrix[i][j] = matrix[i + 1][j];
            }
        }

        //TODO fix this
        for (int j = personIndex; j < vertices - 1; j++) {
            for (int i = 0; i < vertices - 1; i++) {
                matrix[j][i] = matrix[j + 1][i];
            }
        }
    }

    private void removeFriends(Person person) {
        List<Person> friends = getFriendsList(person);

        for (int i = 0; i < personPosition.length; i++) {
            if (personPosition[i].equals(friends)) {

            }
        }
    }

    public void makeFriends(Person person, Person person2) {
        if (person.equals(person2)) {
            System.out.println("You cannot make friends with the same person");
            return;
        }
        int personOneIndex = getPersonIndex(person);
        int personTwoIndex = getPersonIndex(person2);

        matrix[personOneIndex][personTwoIndex] = 1;
        matrix[personTwoIndex][personOneIndex] = 1;
    }

    public List<Person> getFriendsList(Person person) {
        return List.of();
    }

    private int getPersonIndex(Person person) {
        int result = -1;
        for (int i = 0; i < personPosition.length; i++) {
            if (personPosition[i].equals(person)) {
                result = i;
                break;
            }
        }
        return result;
    }

    public void printGraph() {
        for (int i = 0; i < vertices; i++) {
            for (int j = 0; j < vertices; j++) {
                System.out.print(matrix[i][j]);
            }
            System.out.println();
        }
    }
}
