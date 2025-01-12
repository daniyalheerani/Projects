using UnityEngine;

public class PlayerController : MonoBehaviour
{
    
    public float MovementSpeed = 50f;  // Speed of movement
    public float StepSize = 0.7f;      // Distance moved per step
    public float MinX = 0.7f;          // Minimum X position
    public float MaxX = 5.27f;         // Maximum X position

    private Vector2 targetPos;
    public gameManager manager;        // Reference to GameManager script
    public AudioSource source;
    //private Animator anim;
    
   /* private void Awake()
    {
        anim = GetComponent<Animator>();
    }
   */
    void Start()
    {
        targetPos = transform.position; // Initialize target position
    }

    void Update()
    {
        //float horizontalInput = Input.GetAxis("Horizontal");
        //anim.SetBool("Idle", horizontalInput == 0);
        if (IsMobileInput())
        {
            HandleTouchInput();
        }
        else
        {
            HandleMouseInput();
        }
        
        // Move towards the target position
        transform.position = Vector2.MoveTowards(transform.position, targetPos, MovementSpeed * Time.deltaTime);
        

    }

    private bool IsMobileInput()
    {
        // Detect touch input or mouse input based on the platform
#if UNITY_EDITOR || UNITY_STANDALONE
        return false; // Mouse input in editor or standalone
#else
        return Input.touchCount > 0; // Touch input on mobile
#endif
    }

    void HandleTouchInput()
    {
        if (Input.touchCount > 0)
        {
            Touch touch = Input.GetTouch(0);
            if (touch.phase == TouchPhase.Began)
            {
                if (touch.position.x < Screen.width / 2) // Touch on left side
                {
                    MoveLeft();
                    
                }
                else // Touch on right side
                {
                    MoveRight();
                    
                }
            }
        }
    }

    void HandleMouseInput()
    {
        if (Input.GetMouseButtonDown(0)) // Left-click
        {
            Vector2 mousePos = Input.mousePosition;

            if (mousePos.x < Screen.width / 2) // Click on left side
            {
                MoveLeft();
            }
            else // Click on right side
            {
                MoveRight();
            }
        }
    }

    void MoveLeft()
    {
        //float horizontalInput = Input.GetAxis("Horizontal");
        float newX = Mathf.Max(targetPos.x - StepSize, MinX); // Move left but stay within bounds
        targetPos = new Vector2(newX, transform.position.y);
        Debug.Log("Move Left to: " + newX);
        transform.localScale = new Vector3(-0.6f, 0.6f, 0.6f);
        //anim.SetBool("Run", horizontalInput != 0);
    }

    void MoveRight()
    {
        //float horizontalInput = Input.GetAxis("Horizontal");
        float newX = Mathf.Min(targetPos.x + StepSize, MaxX); // Move right but stay within bounds
        targetPos = new Vector2(newX, transform.position.y);
        Debug.Log("Move Right to: " + newX);
        transform.localScale = new Vector3(0.6f,0.6f,0.6f);
        //anim.SetBool("Run", horizontalInput != 0);
    }


    private void OnCollisionEnter2D(Collision2D collision)
    {
        if (collision.gameObject.tag == "Arrow")
        {
            manager.GameOver(); // End the game
            Destroy(collision.gameObject); // Destroy the arrow object
        }
    }
}
