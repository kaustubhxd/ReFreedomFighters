"""specs_s1054.py - unclaimed-04 batch 54 (docs/20-unclaimed-04.md): 0x6552f0 (thiscall, one byte argument, ret 4).
GUESS: some initialization helper that calls Windows API functions (GetClientRect, ClientToScreen, ClipCursor).
The three API functions are stubbed. Only the hwnd parameter is compared; buffer addresses differ by design."""
from pilot import S


def _setup(c):
    # Stub Windows API imports with logging handlers
    # Note: we don't compare buffer addresses since they differ between exe (stack) and port (locals)

    def get_client_rect(em, r):
        hwnd = em.arg32(0)
        buf = em.arg32(1)
        em.calllog.append(('GetClientRect', 0, 0, (hwnd, 0)))  # Log 0 for buffer instead of actual address
        em.ret(eax=1, argbytes=8)  # stdcall, 2 args

    def client_to_screen(em, r):
        hwnd = em.arg32(0)
        buf = em.arg32(1)
        em.calllog.append(('ClientToScreen', 0, 0, (hwnd, 0)))  # Log 0 for buffer
        em.ret(eax=1, argbytes=8)  # stdcall, 2 args

    def clip_cursor(em, r):
        buf = em.arg32(0)
        em.calllog.append(('ClipCursor', 0, 0, (0,)))  # Log 0 for buffer (or NULL)
        em.ret(eax=1, argbytes=4)  # stdcall, 1 arg

    c.emu.stub_import('GetClientRect', get_client_rect)
    c.emu.stub_import('ClientToScreen', client_to_screen)
    c.emu.stub_import('ClipCursor', clip_cursor)


def _args(c):
    # Create an object large enough to have fields at +0x11e7 and +0x133
    size = 0x2000
    obj = c.emu.alloc(size, 4)
    c.emu.wbytes(obj, bytes(c.rng.getrandbits(8) for _ in range(size)))

    # Set a non-zero dword at obj+0x133 (the parameter passed to functions)
    c.emu.w32(obj + 0x133, c.rng.getrandbits(32) | 1)  # Ensure non-zero

    # The argument is a byte that controls whether functions are called
    arg = c.rng.choice([0, 1, 0xff, c.rng.getrandbits(8)])

    return [obj, arg]


S(0x6552f0, 'unknown::thiscall_iat_init (unknown) thiscall', 'thiscall', None, ret=None, gen=_args,
  setup=_setup, note='unclaimed-04 batch 54; Windows API imports stubbed (buffer addresses not compared)')
