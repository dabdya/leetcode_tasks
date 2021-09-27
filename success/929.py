class Solution:
    def numUniqueEmails(self, emails: List[str]) -> int:
        unique_emails = set()
        
        def normalize(email):
            email, domain = email.split("@")
            email = email.replace(".", "")
            email = email.split("+")[0]
            return email + "@" + domain
        
        for email in emails:
            unique_emails.add(normalize(email))
            
        return len(unique_emails)
    
    """Works for O(n^2) time and O(n) space"""