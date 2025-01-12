using UnityEngine;

public class Aero : MonoBehaviour
{
    public float Speed = 3f;

    void Update()
    {
        transform.Translate(Vector2.down * Speed * Time.deltaTime);

        if(transform.position.y < -5)
        {
            Destroy(gameObject);
        }
    }

    private void OnCollisionEnter2D(Collision2D collision)
    {
        if(collision.gameObject.tag == "Ground")
        {
            Destroy(this.gameObject);  
        }
    }
}
