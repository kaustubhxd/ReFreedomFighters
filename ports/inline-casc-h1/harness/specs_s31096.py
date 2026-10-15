"""specs_s31096.py - Sonnet h1 batch 31096: assert hook at 0x7003b0 always set; log object at 0x700390; /GS check 0x633654 a zero-argument recorder."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, hook_rec, pystub


def r32(c):
    return c.rng.getrandbits(32)


def st(c, n, ret=None, pop=None, side=None):
    return pystub(c, n, ret=r32(c) if ret is None else ret, pop=pop, this=True, side=side)


def _assert_hook(c):
    r = c.rng
    e = c.emu

    def ah(e2, res_):
        e2.calllog.append(('assert',))
        e2.ret(eax=r.getrandbits(32))
    e.w32(0x7003b0, e.stub_fn('assert hook', ah))


def _log(c, n_msg):
    o2 = obj(c, 0x40, {0x2c: st(c, n_msg, pop=0)})
    c.emu.w32(0x700390, obj(c, 0x40, {0x20: st(c, 2, ret=o2)}))


def g601520(c):
    clear_hooks(c)
    _assert_hook(c)
    _log(c, 3)
    return []


def g4744c0(c):
    clear_hooks(c)
    _assert_hook(c)
    return [r32(c) for _ in range(7)]


def g466830(c):
    clear_hooks(c)
    val = r32(c)

    def put(emu, k):
        emu.w32(emu.arg32(1), val)       # the callee fills the caller's local (uninitialised stack otherwise)
    hook_rec(c, 0x633654, 0, pop=0, this=True)   # ECX = cookie ^ ebp ^ ebp = the global cookie, frame independent
    mem = obj(c, 0x40, {0x10: st(c, 4, side=put)})
    me = rnd(c, 0x80)
    c.emu.w32(me + 0x6c, mem)
    return [me, r32(c), r32(c)]


S(0x601520, 'GUESS log via global log object then assert hook', 'cdecl', None, ret='eax', gen=g601520, note='batch31096')
S(0x4744c0, 'GUESS assert hook, returns 0, ret 0x1c', 'stdcall', None, ret='eax', gen=g4744c0, note='batch31096')
S(0x466830, 'GUESS member slot 0x10 with local out-pointer, /GS check', 'thiscall', None, ret='eax', gen=g466830, note='batch31096')
