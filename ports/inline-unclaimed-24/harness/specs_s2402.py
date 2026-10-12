"""specs_s2402.py - decomp area 24, batch 2402: ZCloth::ApplyWind (0x44f0f0).
The cloth object: mode +0x24 (1..4, sometimes 0), wind +0x28 (3 floats), +0x2c float, flags pointer +0x64, triangle
count +0x6c, triangle array +0x70 (6-byte records of three indices < N). Virtual slot 0x84 fills a vector (mode 2),
0x90 fills the wind vector. The positions are N float3s with values that make normals of all sizes (including zero).
The exe helpers (vscalar, vrot, 0x451560) run as original code."""
import struct
from pilot import S, F
from recruits_util import rnd, obj, pystub, clear_hooks, sysobj


def _stub_malloc(c):
    # CRT malloc through its import (cdecl): returns a heap block of the requested size
    def h(em, rr):
        size = em.arg32(0)
        em.ret(eax=em.alloc(max(size, 4), 16), argbytes=0)
    c.emu.stub_import('malloc', h)
    c.emu.stub_import('free', lambda em, rr: em.ret(eax=0, argbytes=0))
    # CRT rand(): a deterministic sequence per run (the counter lives in the heap; reset at every gen)
    ctr = c.emu.alloc(4, 4)
    c.emu.w32(ctr, 0)

    def rnd_h(em, rr):
        k = em.r32(ctr)
        em.w32(ctr, k + 1)
        em.ret(eax=((k * 1103515245 + 12345) >> 16) & 0x7fff, argbytes=0)
    c.emu.stub_import('rand', rnd_h)


def _gen(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    _stub_malloc(c)
    sysobj(c, rand=0.37)   # the engine's random slot (0x1c0), used by the length helper's path
    n = r.randint(3, 8)
    pos = c.emu.alloc(12 * n + 16, 16)
    for i in range(3 * n):
        c.emu.wf32(pos + 4 * i, r.choice([r.uniform(-3, 3), 0.0, 1.0, r.uniform(-0.01, 0.01)]))
    tcount = r.randint(0, 6)
    tri = c.emu.alloc(6 * max(tcount, 1) + 8, 4)
    for k in range(tcount):
        ids = [r.randrange(n) for _ in range(3)]
        for j, v in enumerate(ids):
            e.w16(tri + 6 * k + 2 * j, v)
    flags = c.emu.alloc(4 * n + 8, 4)
    for i in range(n):
        e.w32(flags + 4 * i, r.choice([0, 1]))
    cl = rnd(c, 0x100)
    e.w32(cl + 0x24, r.choice([1, 2, 3, 4, 0]))
    wind = [r.uniform(-2, 2) for _ in range(3)]

    def fill_wind(em, k):   # the fill writes all three components (a partial fill would expose the original's garbage)
        p = em.arg32(0)
        for i, v in enumerate(wind):
            em.wf32(p + 4 * i, v)
    e.w32(cl + 0x6c, tcount)
    e.w32(cl + 0x70, tri)
    e.w32(cl + 0x64, flags)
    for i in range(3):
        e.wf32(cl + 0x28 + 4 * i, r.uniform(-1, 1))
    e.wf32(cl + 0x2c, r.uniform(-1, 1))
    vt = c.emu.alloc(0x100, 4)
    e.w32(vt + 0x84, pystub(c, 1, this=True, stackmark=(0,), side=lambda em, k: [em.wf32(em.arg32(0) + 4 * i, 0.5 + i) for i in range(3)]))
    e.w32(vt + 0x90, pystub(c, 1, this=True, stackmark=(0,), side=fill_wind))
    e.w32(cl, vt)
    return [cl, pos, F(r.uniform(-1.5, 1.5))]


S(0x44f0f0, 'ZCloth::ApplyWind', 'thiscall', None, gen=_gen, note='batch2402')
