"""specs_s200140.py - import thunks."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, hook_rec, pystub, seh_record, seh_chain


def _side(c, o):
    sr = seh_record(c, 2)

    def side(emu, k):
        emu.calllog.append(('vt', emu.r32(o)))
        sr(emu, k)
    return side


def g6078d0(c):
    clear_hooks(c)
    r = c.rng
    c.emu.w32(0x6764a0, pystub(c, 4, ret=lambda emu, k: r.getrandbits(32), pop=0, this=True))
    return [r.getrandbits(32) for _ in range(5)]


S(0x6078d0, 'GUESS import thunk 0x6078d0', 'thiscall', None, ret='eax', gen=g6078d0, note='batch200140')
def g61ba16(c):
    clear_hooks(c)
    r = c.rng
    c.emu.w32(0x676018, pystub(c, 4, ret=lambda emu, k: r.getrandbits(32), pop=0, this=True))
    return [r.getrandbits(32) for _ in range(5)]


S(0x61ba16, 'GUESS import thunk 0x61ba16', 'thiscall', None, ret='eax', gen=g61ba16, note='batch200140')
def g61ba1c(c):
    clear_hooks(c)
    r = c.rng
    c.emu.w32(0x676020, pystub(c, 4, ret=lambda emu, k: r.getrandbits(32), pop=0, this=True))
    return [r.getrandbits(32) for _ in range(5)]


S(0x61ba1c, 'GUESS import thunk 0x61ba1c', 'thiscall', None, ret='eax', gen=g61ba1c, note='batch200140')
def g633648(c):
    clear_hooks(c)
    r = c.rng
    c.emu.w32(0x6762c8, pystub(c, 4, ret=lambda emu, k: r.getrandbits(32), pop=0, this=True))
    return [r.getrandbits(32) for _ in range(5)]


S(0x633648, 'GUESS import thunk 0x633648', 'thiscall', None, ret='eax', gen=g633648, note='batch200140')
def g63364e(c):
    clear_hooks(c)
    r = c.rng
    c.emu.w32(0x67617c, pystub(c, 4, ret=lambda emu, k: r.getrandbits(32), pop=0, this=True))
    return [r.getrandbits(32) for _ in range(5)]


S(0x63364e, 'GUESS import thunk 0x63364e', 'thiscall', None, ret='eax', gen=g63364e, note='batch200140')
def g634aae(c):
    clear_hooks(c)
    r = c.rng
    c.emu.w32(0x6764ac, pystub(c, 4, ret=lambda emu, k: r.getrandbits(32), pop=0, this=True))
    return [r.getrandbits(32) for _ in range(5)]


S(0x634aae, 'GUESS import thunk 0x634aae', 'thiscall', None, ret='eax', gen=g634aae, note='batch200140')
def g634ce0(c):
    clear_hooks(c)
    r = c.rng
    c.emu.w32(0x676468, pystub(c, 4, ret=lambda emu, k: r.getrandbits(32), pop=0, this=True))
    return [r.getrandbits(32) for _ in range(5)]


S(0x634ce0, 'GUESS import thunk 0x634ce0', 'thiscall', None, ret='eax', gen=g634ce0, note='batch200140')
def g634ce6(c):
    clear_hooks(c)
    r = c.rng
    c.emu.w32(0x67646c, pystub(c, 4, ret=lambda emu, k: r.getrandbits(32), pop=0, this=True))
    return [r.getrandbits(32) for _ in range(5)]


S(0x634ce6, 'GUESS import thunk 0x634ce6', 'thiscall', None, ret='eax', gen=g634ce6, note='batch200140')
def g634cec(c):
    clear_hooks(c)
    r = c.rng
    c.emu.w32(0x676470, pystub(c, 4, ret=lambda emu, k: r.getrandbits(32), pop=0, this=True))
    return [r.getrandbits(32) for _ in range(5)]


S(0x634cec, 'GUESS import thunk 0x634cec', 'thiscall', None, ret='eax', gen=g634cec, note='batch200140')
def g634cf2(c):
    clear_hooks(c)
    r = c.rng
    c.emu.w32(0x676478, pystub(c, 4, ret=lambda emu, k: r.getrandbits(32), pop=0, this=True))
    return [r.getrandbits(32) for _ in range(5)]


S(0x634cf2, 'GUESS import thunk 0x634cf2', 'thiscall', None, ret='eax', gen=g634cf2, note='batch200140')
def g634cf8(c):
    clear_hooks(c)
    r = c.rng
    c.emu.w32(0x676464, pystub(c, 4, ret=lambda emu, k: r.getrandbits(32), pop=0, this=True))
    return [r.getrandbits(32) for _ in range(5)]


S(0x634cf8, 'GUESS import thunk 0x634cf8', 'thiscall', None, ret='eax', gen=g634cf8, note='batch200140')
def g634cfe(c):
    clear_hooks(c)
    r = c.rng
    c.emu.w32(0x67647c, pystub(c, 4, ret=lambda emu, k: r.getrandbits(32), pop=0, this=True))
    return [r.getrandbits(32) for _ in range(5)]


S(0x634cfe, 'GUESS import thunk 0x634cfe', 'thiscall', None, ret='eax', gen=g634cfe, note='batch200140')
def g634d04(c):
    clear_hooks(c)
    r = c.rng
    c.emu.w32(0x676474, pystub(c, 4, ret=lambda emu, k: r.getrandbits(32), pop=0, this=True))
    return [r.getrandbits(32) for _ in range(5)]


S(0x634d04, 'GUESS import thunk 0x634d04', 'thiscall', None, ret='eax', gen=g634d04, note='batch200140')
def g634d0a(c):
    clear_hooks(c)
    r = c.rng
    c.emu.w32(0x676290, pystub(c, 4, ret=lambda emu, k: r.getrandbits(32), pop=0, this=True))
    return [r.getrandbits(32) for _ in range(5)]


S(0x634d0a, 'GUESS import thunk 0x634d0a', 'thiscall', None, ret='eax', gen=g634d0a, note='batch200140')
def g634d10(c):
    clear_hooks(c)
    r = c.rng
    c.emu.w32(0x676260, pystub(c, 4, ret=lambda emu, k: r.getrandbits(32), pop=0, this=True))
    return [r.getrandbits(32) for _ in range(5)]


S(0x634d10, 'GUESS import thunk 0x634d10', 'thiscall', None, ret='eax', gen=g634d10, note='batch200140')
def g634d16(c):
    clear_hooks(c)
    r = c.rng
    c.emu.w32(0x676264, pystub(c, 4, ret=lambda emu, k: r.getrandbits(32), pop=0, this=True))
    return [r.getrandbits(32) for _ in range(5)]


S(0x634d16, 'GUESS import thunk 0x634d16', 'thiscall', None, ret='eax', gen=g634d16, note='batch200140')
def g634d1c(c):
    clear_hooks(c)
    r = c.rng
    c.emu.w32(0x676268, pystub(c, 4, ret=lambda emu, k: r.getrandbits(32), pop=0, this=True))
    return [r.getrandbits(32) for _ in range(5)]


S(0x634d1c, 'GUESS import thunk 0x634d1c', 'thiscall', None, ret='eax', gen=g634d1c, note='batch200140')
def g634d22(c):
    clear_hooks(c)
    r = c.rng
    c.emu.w32(0x67626c, pystub(c, 4, ret=lambda emu, k: r.getrandbits(32), pop=0, this=True))
    return [r.getrandbits(32) for _ in range(5)]


S(0x634d22, 'GUESS import thunk 0x634d22', 'thiscall', None, ret='eax', gen=g634d22, note='batch200140')
def g634d28(c):
    clear_hooks(c)
    r = c.rng
    c.emu.w32(0x676278, pystub(c, 4, ret=lambda emu, k: r.getrandbits(32), pop=0, this=True))
    return [r.getrandbits(32) for _ in range(5)]


S(0x634d28, 'GUESS import thunk 0x634d28', 'thiscall', None, ret='eax', gen=g634d28, note='batch200140')
def g634d2e(c):
    clear_hooks(c)
    r = c.rng
    c.emu.w32(0x67627c, pystub(c, 4, ret=lambda emu, k: r.getrandbits(32), pop=0, this=True))
    return [r.getrandbits(32) for _ in range(5)]


S(0x634d2e, 'GUESS import thunk 0x634d2e', 'thiscall', None, ret='eax', gen=g634d2e, note='batch200140')
def g634d34(c):
    clear_hooks(c)
    r = c.rng
    c.emu.w32(0x676280, pystub(c, 4, ret=lambda emu, k: r.getrandbits(32), pop=0, this=True))
    return [r.getrandbits(32) for _ in range(5)]


S(0x634d34, 'GUESS import thunk 0x634d34', 'thiscall', None, ret='eax', gen=g634d34, note='batch200140')
def g634d3a(c):
    clear_hooks(c)
    r = c.rng
    c.emu.w32(0x676284, pystub(c, 4, ret=lambda emu, k: r.getrandbits(32), pop=0, this=True))
    return [r.getrandbits(32) for _ in range(5)]


S(0x634d3a, 'GUESS import thunk 0x634d3a', 'thiscall', None, ret='eax', gen=g634d3a, note='batch200140')
def g634d40(c):
    clear_hooks(c)
    r = c.rng
    c.emu.w32(0x676288, pystub(c, 4, ret=lambda emu, k: r.getrandbits(32), pop=0, this=True))
    return [r.getrandbits(32) for _ in range(5)]


S(0x634d40, 'GUESS import thunk 0x634d40', 'thiscall', None, ret='eax', gen=g634d40, note='batch200140')
def g634d46(c):
    clear_hooks(c)
    r = c.rng
    c.emu.w32(0x67628c, pystub(c, 4, ret=lambda emu, k: r.getrandbits(32), pop=0, this=True))
    return [r.getrandbits(32) for _ in range(5)]


S(0x634d46, 'GUESS import thunk 0x634d46', 'thiscall', None, ret='eax', gen=g634d46, note='batch200140')
def g634d52(c):
    clear_hooks(c)
    r = c.rng
    c.emu.w32(0x6762ec, pystub(c, 4, ret=lambda emu, k: r.getrandbits(32), pop=0, this=True))
    return [r.getrandbits(32) for _ in range(5)]


S(0x634d52, 'GUESS import thunk 0x634d52', 'thiscall', None, ret='eax', gen=g634d52, note='batch200140')
def g634d58(c):
    clear_hooks(c)
    r = c.rng
    c.emu.w32(0x6762f0, pystub(c, 4, ret=lambda emu, k: r.getrandbits(32), pop=0, this=True))
    return [r.getrandbits(32) for _ in range(5)]


S(0x634d58, 'GUESS import thunk 0x634d58', 'thiscall', None, ret='eax', gen=g634d58, note='batch200140')
def g634d5e(c):
    clear_hooks(c)
    r = c.rng
    c.emu.w32(0x676374, pystub(c, 4, ret=lambda emu, k: r.getrandbits(32), pop=0, this=True))
    return [r.getrandbits(32) for _ in range(5)]


S(0x634d5e, 'GUESS import thunk 0x634d5e', 'thiscall', None, ret='eax', gen=g634d5e, note='batch200140')
def g634d64(c):
    clear_hooks(c)
    r = c.rng
    c.emu.w32(0x6763c8, pystub(c, 4, ret=lambda emu, k: r.getrandbits(32), pop=0, this=True))
    return [r.getrandbits(32) for _ in range(5)]


S(0x634d64, 'GUESS import thunk 0x634d64', 'thiscall', None, ret='eax', gen=g634d64, note='batch200140')
def g634d6a(c):
    clear_hooks(c)
    r = c.rng
    c.emu.w32(0x676308, pystub(c, 4, ret=lambda emu, k: r.getrandbits(32), pop=0, this=True))
    return [r.getrandbits(32) for _ in range(5)]


S(0x634d6a, 'GUESS import thunk 0x634d6a', 'thiscall', None, ret='eax', gen=g634d6a, note='batch200140')
def g634d70(c):
    clear_hooks(c)
    r = c.rng
    c.emu.w32(0x676320, pystub(c, 4, ret=lambda emu, k: r.getrandbits(32), pop=0, this=True))
    return [r.getrandbits(32) for _ in range(5)]


S(0x634d70, 'GUESS import thunk 0x634d70', 'thiscall', None, ret='eax', gen=g634d70, note='batch200140')
def g634d76(c):
    clear_hooks(c)
    r = c.rng
    c.emu.w32(0x676338, pystub(c, 4, ret=lambda emu, k: r.getrandbits(32), pop=0, this=True))
    return [r.getrandbits(32) for _ in range(5)]


S(0x634d76, 'GUESS import thunk 0x634d76', 'thiscall', None, ret='eax', gen=g634d76, note='batch200140')
def g634d7c(c):
    clear_hooks(c)
    r = c.rng
    c.emu.w32(0x676330, pystub(c, 4, ret=lambda emu, k: r.getrandbits(32), pop=0, this=True))
    return [r.getrandbits(32) for _ in range(5)]


S(0x634d7c, 'GUESS import thunk 0x634d7c', 'thiscall', None, ret='eax', gen=g634d7c, note='batch200140')
def g634d82(c):
    clear_hooks(c)
    r = c.rng
    c.emu.w32(0x6763b8, pystub(c, 4, ret=lambda emu, k: r.getrandbits(32), pop=0, this=True))
    return [r.getrandbits(32) for _ in range(5)]


S(0x634d82, 'GUESS import thunk 0x634d82', 'thiscall', None, ret='eax', gen=g634d82, note='batch200140')
def g634d88(c):
    clear_hooks(c)
    r = c.rng
    c.emu.w32(0x6763c0, pystub(c, 4, ret=lambda emu, k: r.getrandbits(32), pop=0, this=True))
    return [r.getrandbits(32) for _ in range(5)]


S(0x634d88, 'GUESS import thunk 0x634d88', 'thiscall', None, ret='eax', gen=g634d88, note='batch200140')
def g634d8e(c):
    clear_hooks(c)
    r = c.rng
    c.emu.w32(0x6763d0, pystub(c, 4, ret=lambda emu, k: r.getrandbits(32), pop=0, this=True))
    return [r.getrandbits(32) for _ in range(5)]


S(0x634d8e, 'GUESS import thunk 0x634d8e', 'thiscall', None, ret='eax', gen=g634d8e, note='batch200140')
def g634d94(c):
    clear_hooks(c)
    r = c.rng
    c.emu.w32(0x6763e0, pystub(c, 4, ret=lambda emu, k: r.getrandbits(32), pop=0, this=True))
    return [r.getrandbits(32) for _ in range(5)]


S(0x634d94, 'GUESS import thunk 0x634d94', 'thiscall', None, ret='eax', gen=g634d94, note='batch200140')
def g634d9a(c):
    clear_hooks(c)
    r = c.rng
    c.emu.w32(0x6763e4, pystub(c, 4, ret=lambda emu, k: r.getrandbits(32), pop=0, this=True))
    return [r.getrandbits(32) for _ in range(5)]


S(0x634d9a, 'GUESS import thunk 0x634d9a', 'thiscall', None, ret='eax', gen=g634d9a, note='batch200140')
def g634da0(c):
    clear_hooks(c)
    r = c.rng
    c.emu.w32(0x6763fc, pystub(c, 4, ret=lambda emu, k: r.getrandbits(32), pop=0, this=True))
    return [r.getrandbits(32) for _ in range(5)]


S(0x634da0, 'GUESS import thunk 0x634da0', 'thiscall', None, ret='eax', gen=g634da0, note='batch200140')
def g634da6(c):
    clear_hooks(c)
    r = c.rng
    c.emu.w32(0x676340, pystub(c, 4, ret=lambda emu, k: r.getrandbits(32), pop=0, this=True))
    return [r.getrandbits(32) for _ in range(5)]


S(0x634da6, 'GUESS import thunk 0x634da6', 'thiscall', None, ret='eax', gen=g634da6, note='batch200140')
def g634dac(c):
    clear_hooks(c)
    r = c.rng
    c.emu.w32(0x676348, pystub(c, 4, ret=lambda emu, k: r.getrandbits(32), pop=0, this=True))
    return [r.getrandbits(32) for _ in range(5)]


S(0x634dac, 'GUESS import thunk 0x634dac', 'thiscall', None, ret='eax', gen=g634dac, note='batch200140')
def g634db2(c):
    clear_hooks(c)
    r = c.rng
    c.emu.w32(0x67634c, pystub(c, 4, ret=lambda emu, k: r.getrandbits(32), pop=0, this=True))
    return [r.getrandbits(32) for _ in range(5)]


S(0x634db2, 'GUESS import thunk 0x634db2', 'thiscall', None, ret='eax', gen=g634db2, note='batch200140')
def g634db8(c):
    clear_hooks(c)
    r = c.rng
    c.emu.w32(0x676350, pystub(c, 4, ret=lambda emu, k: r.getrandbits(32), pop=0, this=True))
    return [r.getrandbits(32) for _ in range(5)]


S(0x634db8, 'GUESS import thunk 0x634db8', 'thiscall', None, ret='eax', gen=g634db8, note='batch200140')
def g634dbe(c):
    clear_hooks(c)
    r = c.rng
    c.emu.w32(0x676354, pystub(c, 4, ret=lambda emu, k: r.getrandbits(32), pop=0, this=True))
    return [r.getrandbits(32) for _ in range(5)]


S(0x634dbe, 'GUESS import thunk 0x634dbe', 'thiscall', None, ret='eax', gen=g634dbe, note='batch200140')
def g634dc4(c):
    clear_hooks(c)
    r = c.rng
    c.emu.w32(0x676358, pystub(c, 4, ret=lambda emu, k: r.getrandbits(32), pop=0, this=True))
    return [r.getrandbits(32) for _ in range(5)]


S(0x634dc4, 'GUESS import thunk 0x634dc4', 'thiscall', None, ret='eax', gen=g634dc4, note='batch200140')
def g634dca(c):
    clear_hooks(c)
    r = c.rng
    c.emu.w32(0x67635c, pystub(c, 4, ret=lambda emu, k: r.getrandbits(32), pop=0, this=True))
    return [r.getrandbits(32) for _ in range(5)]


S(0x634dca, 'GUESS import thunk 0x634dca', 'thiscall', None, ret='eax', gen=g634dca, note='batch200140')
def g634dd0(c):
    clear_hooks(c)
    r = c.rng
    c.emu.w32(0x676450, pystub(c, 4, ret=lambda emu, k: r.getrandbits(32), pop=0, this=True))
    return [r.getrandbits(32) for _ in range(5)]


S(0x634dd0, 'GUESS import thunk 0x634dd0', 'thiscall', None, ret='eax', gen=g634dd0, note='batch200140')
def g634dd6(c):
    clear_hooks(c)
    r = c.rng
    c.emu.w32(0x67632c, pystub(c, 4, ret=lambda emu, k: r.getrandbits(32), pop=0, this=True))
    return [r.getrandbits(32) for _ in range(5)]


S(0x634dd6, 'GUESS import thunk 0x634dd6', 'thiscall', None, ret='eax', gen=g634dd6, note='batch200140')
def g634ddc(c):
    clear_hooks(c)
    r = c.rng
    c.emu.w32(0x67631c, pystub(c, 4, ret=lambda emu, k: r.getrandbits(32), pop=0, this=True))
    return [r.getrandbits(32) for _ in range(5)]


S(0x634ddc, 'GUESS import thunk 0x634ddc', 'thiscall', None, ret='eax', gen=g634ddc, note='batch200140')
def g634de2(c):
    clear_hooks(c)
    r = c.rng
    c.emu.w32(0x676318, pystub(c, 4, ret=lambda emu, k: r.getrandbits(32), pop=0, this=True))
    return [r.getrandbits(32) for _ in range(5)]


S(0x634de2, 'GUESS import thunk 0x634de2', 'thiscall', None, ret='eax', gen=g634de2, note='batch200140')
def g634de8(c):
    clear_hooks(c)
    r = c.rng
    c.emu.w32(0x676314, pystub(c, 4, ret=lambda emu, k: r.getrandbits(32), pop=0, this=True))
    return [r.getrandbits(32) for _ in range(5)]


S(0x634de8, 'GUESS import thunk 0x634de8', 'thiscall', None, ret='eax', gen=g634de8, note='batch200140')
def g634dee(c):
    clear_hooks(c)
    r = c.rng
    c.emu.w32(0x6762f4, pystub(c, 4, ret=lambda emu, k: r.getrandbits(32), pop=0, this=True))
    return [r.getrandbits(32) for _ in range(5)]


S(0x634dee, 'GUESS import thunk 0x634dee', 'thiscall', None, ret='eax', gen=g634dee, note='batch200140')
def g634df4(c):
    clear_hooks(c)
    r = c.rng
    c.emu.w32(0x6762f8, pystub(c, 4, ret=lambda emu, k: r.getrandbits(32), pop=0, this=True))
    return [r.getrandbits(32) for _ in range(5)]


S(0x634df4, 'GUESS import thunk 0x634df4', 'thiscall', None, ret='eax', gen=g634df4, note='batch200140')
def g634dfa(c):
    clear_hooks(c)
    r = c.rng
    c.emu.w32(0x676334, pystub(c, 4, ret=lambda emu, k: r.getrandbits(32), pop=0, this=True))
    return [r.getrandbits(32) for _ in range(5)]


S(0x634dfa, 'GUESS import thunk 0x634dfa', 'thiscall', None, ret='eax', gen=g634dfa, note='batch200140')
def g634e00(c):
    clear_hooks(c)
    r = c.rng
    c.emu.w32(0x67630c, pystub(c, 4, ret=lambda emu, k: r.getrandbits(32), pop=0, this=True))
    return [r.getrandbits(32) for _ in range(5)]


S(0x634e00, 'GUESS import thunk 0x634e00', 'thiscall', None, ret='eax', gen=g634e00, note='batch200140')
def g634e06(c):
    clear_hooks(c)
    r = c.rng
    c.emu.w32(0x676310, pystub(c, 4, ret=lambda emu, k: r.getrandbits(32), pop=0, this=True))
    return [r.getrandbits(32) for _ in range(5)]


S(0x634e06, 'GUESS import thunk 0x634e06', 'thiscall', None, ret='eax', gen=g634e06, note='batch200140')
def g634e0c(c):
    clear_hooks(c)
    r = c.rng
    c.emu.w32(0x676344, pystub(c, 4, ret=lambda emu, k: r.getrandbits(32), pop=0, this=True))
    return [r.getrandbits(32) for _ in range(5)]


S(0x634e0c, 'GUESS import thunk 0x634e0c', 'thiscall', None, ret='eax', gen=g634e0c, note='batch200140')
def g634e18(c):
    clear_hooks(c)
    r = c.rng
    c.emu.w32(0x67639c, pystub(c, 4, ret=lambda emu, k: r.getrandbits(32), pop=0, this=True))
    return [r.getrandbits(32) for _ in range(5)]


S(0x634e18, 'GUESS import thunk 0x634e18', 'thiscall', None, ret='eax', gen=g634e18, note='batch200140')
def g634e1e(c):
    clear_hooks(c)
    r = c.rng
    c.emu.w32(0x676324, pystub(c, 4, ret=lambda emu, k: r.getrandbits(32), pop=0, this=True))
    return [r.getrandbits(32) for _ in range(5)]


S(0x634e1e, 'GUESS import thunk 0x634e1e', 'thiscall', None, ret='eax', gen=g634e1e, note='batch200140')
def g634e24(c):
    clear_hooks(c)
    r = c.rng
    c.emu.w32(0x676398, pystub(c, 4, ret=lambda emu, k: r.getrandbits(32), pop=0, this=True))
    return [r.getrandbits(32) for _ in range(5)]


S(0x634e24, 'GUESS import thunk 0x634e24', 'thiscall', None, ret='eax', gen=g634e24, note='batch200140')
def g634e2a(c):
    clear_hooks(c)
    r = c.rng
    c.emu.w32(0x676390, pystub(c, 4, ret=lambda emu, k: r.getrandbits(32), pop=0, this=True))
    return [r.getrandbits(32) for _ in range(5)]


S(0x634e2a, 'GUESS import thunk 0x634e2a', 'thiscall', None, ret='eax', gen=g634e2a, note='batch200140')
def g634e30(c):
    clear_hooks(c)
    r = c.rng
    c.emu.w32(0x67638c, pystub(c, 4, ret=lambda emu, k: r.getrandbits(32), pop=0, this=True))
    return [r.getrandbits(32) for _ in range(5)]


S(0x634e30, 'GUESS import thunk 0x634e30', 'thiscall', None, ret='eax', gen=g634e30, note='batch200140')
def g634e36(c):
    clear_hooks(c)
    r = c.rng
    c.emu.w32(0x676388, pystub(c, 4, ret=lambda emu, k: r.getrandbits(32), pop=0, this=True))
    return [r.getrandbits(32) for _ in range(5)]


S(0x634e36, 'GUESS import thunk 0x634e36', 'thiscall', None, ret='eax', gen=g634e36, note='batch200140')
def g634e3c(c):
    clear_hooks(c)
    r = c.rng
    c.emu.w32(0x676384, pystub(c, 4, ret=lambda emu, k: r.getrandbits(32), pop=0, this=True))
    return [r.getrandbits(32) for _ in range(5)]


S(0x634e3c, 'GUESS import thunk 0x634e3c', 'thiscall', None, ret='eax', gen=g634e3c, note='batch200140')
def g634e42(c):
    clear_hooks(c)
    r = c.rng
    c.emu.w32(0x6763bc, pystub(c, 4, ret=lambda emu, k: r.getrandbits(32), pop=0, this=True))
    return [r.getrandbits(32) for _ in range(5)]


S(0x634e42, 'GUESS import thunk 0x634e42', 'thiscall', None, ret='eax', gen=g634e42, note='batch200140')
def g634e48(c):
    clear_hooks(c)
    r = c.rng
    c.emu.w32(0x676380, pystub(c, 4, ret=lambda emu, k: r.getrandbits(32), pop=0, this=True))
    return [r.getrandbits(32) for _ in range(5)]


S(0x634e48, 'GUESS import thunk 0x634e48', 'thiscall', None, ret='eax', gen=g634e48, note='batch200140')
def g634e54(c):
    clear_hooks(c)
    r = c.rng
    c.emu.w32(0x676378, pystub(c, 4, ret=lambda emu, k: r.getrandbits(32), pop=0, this=True))
    return [r.getrandbits(32) for _ in range(5)]


S(0x634e54, 'GUESS import thunk 0x634e54', 'thiscall', None, ret='eax', gen=g634e54, note='batch200140')
def g634e5a(c):
    clear_hooks(c)
    r = c.rng
    c.emu.w32(0x676300, pystub(c, 4, ret=lambda emu, k: r.getrandbits(32), pop=0, this=True))
    return [r.getrandbits(32) for _ in range(5)]


S(0x634e5a, 'GUESS import thunk 0x634e5a', 'thiscall', None, ret='eax', gen=g634e5a, note='batch200140')
def g634e60(c):
    clear_hooks(c)
    r = c.rng
    c.emu.w32(0x6762e8, pystub(c, 4, ret=lambda emu, k: r.getrandbits(32), pop=0, this=True))
    return [r.getrandbits(32) for _ in range(5)]


S(0x634e60, 'GUESS import thunk 0x634e60', 'thiscall', None, ret='eax', gen=g634e60, note='batch200140')
def g634e66(c):
    clear_hooks(c)
    r = c.rng
    c.emu.w32(0x6763cc, pystub(c, 4, ret=lambda emu, k: r.getrandbits(32), pop=0, this=True))
    return [r.getrandbits(32) for _ in range(5)]


S(0x634e66, 'GUESS import thunk 0x634e66', 'thiscall', None, ret='eax', gen=g634e66, note='batch200140')
def g634e6c(c):
    clear_hooks(c)
    r = c.rng
    c.emu.w32(0x67633c, pystub(c, 4, ret=lambda emu, k: r.getrandbits(32), pop=0, this=True))
    return [r.getrandbits(32) for _ in range(5)]


S(0x634e6c, 'GUESS import thunk 0x634e6c', 'thiscall', None, ret='eax', gen=g634e6c, note='batch200140')
def g634e72(c):
    clear_hooks(c)
    r = c.rng
    c.emu.w32(0x676370, pystub(c, 4, ret=lambda emu, k: r.getrandbits(32), pop=0, this=True))
    return [r.getrandbits(32) for _ in range(5)]


S(0x634e72, 'GUESS import thunk 0x634e72', 'thiscall', None, ret='eax', gen=g634e72, note='batch200140')
def g634e78(c):
    clear_hooks(c)
    r = c.rng
    c.emu.w32(0x67636c, pystub(c, 4, ret=lambda emu, k: r.getrandbits(32), pop=0, this=True))
    return [r.getrandbits(32) for _ in range(5)]


S(0x634e78, 'GUESS import thunk 0x634e78', 'thiscall', None, ret='eax', gen=g634e78, note='batch200140')
def g634e7e(c):
    clear_hooks(c)
    r = c.rng
    c.emu.w32(0x676368, pystub(c, 4, ret=lambda emu, k: r.getrandbits(32), pop=0, this=True))
    return [r.getrandbits(32) for _ in range(5)]


S(0x634e7e, 'GUESS import thunk 0x634e7e', 'thiscall', None, ret='eax', gen=g634e7e, note='batch200140')
def g634e84(c):
    clear_hooks(c)
    r = c.rng
    c.emu.w32(0x676364, pystub(c, 4, ret=lambda emu, k: r.getrandbits(32), pop=0, this=True))
    return [r.getrandbits(32) for _ in range(5)]


S(0x634e84, 'GUESS import thunk 0x634e84', 'thiscall', None, ret='eax', gen=g634e84, note='batch200140')
def g634e8a(c):
    clear_hooks(c)
    r = c.rng
    c.emu.w32(0x6763a4, pystub(c, 4, ret=lambda emu, k: r.getrandbits(32), pop=0, this=True))
    return [r.getrandbits(32) for _ in range(5)]


S(0x634e8a, 'GUESS import thunk 0x634e8a', 'thiscall', None, ret='eax', gen=g634e8a, note='batch200140')
def g663bc2(c):
    clear_hooks(c)
    r = c.rng
    c.emu.w32(0x676158, pystub(c, 4, ret=lambda emu, k: r.getrandbits(32), pop=0, this=True))
    return [r.getrandbits(32) for _ in range(5)]


S(0x663bc2, 'GUESS import thunk 0x663bc2', 'thiscall', None, ret='eax', gen=g663bc2, note='batch200140')
