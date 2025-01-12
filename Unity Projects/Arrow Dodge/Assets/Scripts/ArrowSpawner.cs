using UnityEngine;

public class ArrowSpawner : MonoBehaviour
{
    [Header("Aero Stats")]
    public GameObject AeroPrefab;
    public float SpawnInterval = 1f;
    public float SpawnRange = 5f;
    public float SpeedMultiplier = 0.075f;

    public GameObject[] spawners;

    public float timer;
    private float FallSpeed = 2.5f;

    void Start()
    {
        timer = 0f;
    }

    void Update()
    {
        timer += Time.deltaTime;
        if(timer >= SpawnInterval)
        {
            SpawnAero();
            timer = 0f;

            FallSpeed += SpeedMultiplier;
        }
    }

    public void SpawnAero()
    {

        int index = Random.Range(0, spawners.Length);
        GameObject NewAero = Instantiate(AeroPrefab, spawners[index].transform.position, Quaternion.identity);
        NewAero.GetComponent<Aero>().Speed = FallSpeed;

    }
}
