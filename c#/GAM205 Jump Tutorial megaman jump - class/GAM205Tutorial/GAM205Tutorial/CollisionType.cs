using System;

namespace GAM205Tutorial
{
    /// <summary>
    /// Represents the type of collision taking place.
    /// </summary>
    [Flags]
    public enum CollisionType
    {
        None = 0x00,
        Left = 0x01,
        Right = 0x02,
        Top = 0x04,
        Bottom = 0x08
    }
}