using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Security.Claims;
using System.Threading.Tasks;
using System.Web;
using System.Web.Configuration;
using System.Web.Mvc;
using Microsoft.AspNet.Identity;
using Microsoft.AspNet.Identity.EntityFramework;
using Microsoft.Owin.Security;

namespace ArduinoBot
{
    public partial class Startup
	{
        public void CreateRoles()
        {
            var roleManager = new RoleManager<IdentityRole>(new RoleStore<IdentityRole>());

            if (!roleManager.RoleExists("Admin"))
            {
                var role = new Microsoft.AspNet.Identity.EntityFramework.IdentityRole();
                role.Name = "Admin";
                roleManager.Create(role);
            }
            if (!roleManager.RoleExists("User"))
            {
                var role = new Microsoft.AspNet.Identity.EntityFramework.IdentityRole();
                role.Name = "User";
                roleManager.Create(role);
            }
            if (!roleManager.RoleExists("Bot"))
            {
                var role = new Microsoft.AspNet.Identity.EntityFramework.IdentityRole();
                role.Name = "Bot";
                roleManager.Create(role);
            }
        }


        public void CreateUsers()
        {

            //            sqllocaldb.exe stop v11.0
            //sqllocaldb.exe delete v11.0

            //  input "Enable-Migrations"
            //  input "Add-Migration init"
            //  input "Update-Database"


            var userManager = new UserManager<IdentityUser>(new UserStore<IdentityUser>());

            if (userManager.FindByName("Admin") == null)
            {
                var user = new Microsoft.AspNet.Identity.EntityFramework.IdentityUser();
                user.UserName = "Admin";
                userManager.Create(user, WebConfigurationManager.AppSettings["AdminAccount"]);  // potential problem with password
                userManager.AddToRole(user.Id, "Admin");
            }

            if (userManager.FindByName("Bot") == null)
            {
                var user = new Microsoft.AspNet.Identity.EntityFramework.IdentityUser();
                user.UserName = "Bot";
                userManager.Create(user, WebConfigurationManager.AppSettings["BotAccessToken"]);  // potential problem with password
                userManager.AddToRole(user.Id, "Bot");
            }
        }


	}
}